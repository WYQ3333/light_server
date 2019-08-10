#ifndef __M_CLI_H__
#define __M_CLI_H__
#include "common.h"
#include <string>
#include <unordered_map>
#include <sys/stat.h>
#include <sys/inotify.h>


typedef struct inotify_event InotifyEvent;

class Client{
    private:
        char *_root_dir;
        char *_str_addr;
        char *_str_port;
        char *_user_name;
        BlockQueue _queue;
    public:
        Client(char *root_dir, char *str_addr, char *str_port, char *user_name):
            _root_dir(root_dir),
            _str_addr(str_addr),
            _str_port(str_port),
            _user_name(user_name),
            _queue() { }

        char *GetRootDir(){
            return _root_dir;
        }

        char *GetStrAddr(){
            return _str_addr;
        }

        char *GetStrPort(){
            return _str_port;
        }

        char *GetUserName(){
            return _user_name;
        }

        bool QueuePushData(void *path){
            _queue.PushData(path);
            return true;
        }

        bool QueuePopData(void **path){
            _queue.PopData(path);
            return true;
        }
};

class CScanFile{
    private:
        Client *_client;
        int _inotify_fd;
        char _event_buff[MAX_BUFF];
        uint64_t _total_size;
        uint64_t _cur_size;
        uint64_t _lst_event;
        std::unordered_map<int, std::string> _listen_dir;

        bool InitInotify(){
            _inotify_fd = inotify_init();
            CHECK_ERR(_inotify_fd);
            return true;
        }

        bool AddListenDir(std::string &path){
            int wd;
            wd = inotify_add_watch(_inotify_fd, path.c_str(), _lst_event);
            CHECK_ERR(wd);
            _listen_dir.insert(std::make_pair(wd, path));
            return true;
        }

        bool DelListenDir(int wd){
            CHECK_ERR(inotify_rm_watch(_inotify_fd, wd));
            _listen_dir.erase(wd);
            return true;
        }

        bool GetListenDir(int wd, std::string *path){
            auto it = _listen_dir.find(wd);
            if (it == _listen_dir.end()) {
                return false;
            }
            *path = it->second;
            return true;
        }

        bool GetFullFile(InotifyEvent *evs, std::string *file){
            CHECK_RET(evs);
            std::string path;
            CHECK_RET(GetListenDir(evs->wd, &path));
            char tmp[MAX_PATH] = {0};
            int s = sprintf(tmp,"%s/%s",path.c_str(), evs->name);
            file->assign(tmp, s);
            return true;
        }

        bool CheckEvent(){
            fd_set rds;
            FD_ZERO(&rds);
            FD_SET(_inotify_fd, &rds);
            CHECK_ERR(select(_inotify_fd + 1, &rds, NULL, NULL, NULL));
            return true;
        }

        InotifyEvent *NextEvent(){
            InotifyEvent *p_evs = NULL;
            if (_total_size == 0) {
                _cur_size = 0;
                _total_size = read(_inotify_fd, _event_buff, 
                        MAX_BUFF);
                if (_total_size <= 0) {
                    return NULL;
                }
                p_evs = (InotifyEvent*)_event_buff;
                _cur_size += (sizeof(InotifyEvent) + p_evs->len);
                if (_cur_size == _total_size) {
                    _total_size = 0;
                }
            }else if (_cur_size < (_total_size - sizeof(InotifyEvent))) {
                p_evs = (InotifyEvent*)(_event_buff + _cur_size);
                _cur_size += (sizeof(InotifyEvent) + p_evs->len);
                if (_cur_size == _total_size) {
                    _total_size = 0;
                }else if (_cur_size > _total_size) {
                    _total_size = 0;
                    return NULL;
                }
            }
            return p_evs;
        }
    public:
        CScanFile(Client *client)
            :_client(client)
            ,_total_size(0)
            ,_cur_size(0)
            ,_lst_event(IN_CLOSE_WRITE)
        { }

        ~CScanFile(){
            close(_inotify_fd);
        }

        bool Start(){
            std::string root = _client->GetRootDir();
            CHECK_RET(InitInotify());
            CHECK_RET(AddListenDir(root));
            while(1) {
                if (CheckEvent()) {
                    std::string *file = new std::string();
                    if (GetFullFile(NextEvent(), file)) {
                        //printf("file : %s is close for write\n", file->c_str());
                        _client->QueuePushData((void*)file);
                    }
                }
            }
            return true;
        }

};

class CTransFile{
    private:
        Client *_client;
        TcpSocket _socket;
        int _cur_statu;
        int _file_fd;
        uint64_t _total_size;
        std::string _username;
        std::string _password;
        char *_root_dir;

        bool StopCurfile(){
            if (_file_fd != -1) {
                close(_file_fd);
            }
            _file_fd = -1;
            _total_size = 0;
            _cur_statu = N_SNDHDR;
        }

        bool CommonReq(_req_type_t req_type, uint64_t len){
            CommReq req(req_type, len);
            if (_socket.Send((void*)&req, sizeof(CommReq)) < 0) {
                printf("send com req error\n");
                return false;
            }
            return true;
        }

        bool LoginReq(){
            std::cout << "LoginReq " << std::endl;
            CHECK_RET(CommonReq(REQ_LOGIN, sizeof(LoginInfo)));
            LoginInfo user(_username, _password);
            if (_socket.Send((void*)&user, sizeof(LoginInfo)) < 0) {
                printf("send user info error\n");
                return false;
            }
            //下一步该接收登陆回复
            _cur_statu = N_RCVLOGIN;
            return true;
        }

        bool LoginRsp(){
            CommReq rsp;
            std::cout << "LoginRsp" << std::endl;
            if (_socket.Recv((void*)&rsp, sizeof(CommReq)) < 0) {
                printf("recv login rsp error\n");
                return false;
            }
            if (!rsp.IsLoginRsp()) {
                printf("not login rsp close!!\n");
                return false;
            }
            if (rsp.GetLen() != 0) {
                char buff[1024] = {0};
                CHECK_ERR(_socket.Recv(buff, rsp.GetLen()));
                printf("login failed:%s\n", buff);
                return false;
            }
            //接受登陆回复成功后，开始传输文件头部
            _cur_statu = N_SNDHDR;
            return true;
        }

        bool SendFileHdr(std::string &file){
            struct stat st;
            if (stat(file.c_str(), &st) < 0) {
                printf("get file stat error\n");
                return false;
            }
            std::cout << "st.st_size" << st.st_size << std::endl;
            CHECK_RET(CommonReq(REQ_UFILE, sizeof(FileInfo)));
            //传递去掉了rootdir之后的路径
            std::string sfile(file, strlen(_root_dir));
            FileInfo freq(sfile, st.st_size);
            printf("send file name:%s-len:%lu\n", freq.GetName(), freq.GetLen());
            if (_socket.Send((void*)&freq, sizeof(FileInfo)) < 0) {
                printf("send file hdr req error\n");
                return false;
            }
            if((_file_fd = open(file.c_str(), O_RDONLY)) < 0) {
                printf("open file:%s error\n", file.c_str());
                return false;
            }
            _total_size = st.st_size;
            //发送文件头之后，开始下一步发送文件数据
            _cur_statu = N_SNDBODY;
            return true;
        }

        bool SendFileBody(){
            int slen = 0;
            int alen = 0;
            char buff[1024];
            while(alen < _total_size) {
                slen = read(_file_fd, buff, 1024);
                CHECK_RET(_socket.Send(buff, slen));
                alen += slen;
            }
            _cur_statu = N_SNDOVER;
            return true;
        }

        bool SendFileOver(){
            close(_file_fd);
            _file_fd = -1;
            _total_size = 0;
            //文件发送完毕，准备发送下一个文件
            _cur_statu = N_SNDHDR;
            //接收回复消息
            CommReq rsp;
            CHECK_ERR(_socket.Recv((void*)&rsp, sizeof(CommReq)));
            if (!rsp.IsUpLoadRsp()) {
                printf("not file rsp \n");
                return false;
            }
            if (rsp.GetLen() != 0) {
                char buff[1024] = {0};
                CHECK_ERR(_socket.Recv(buff, rsp.GetLen()));
                printf("send file failed:%s\n", buff);
                return true;
            }
            printf("file trans success!!\n");
            return true;
        }
    public:
        CTransFile(Client *client)
            :_client(client)
             , _cur_statu(N_START)
             , _file_fd(-1)
             ,_total_size(0){
                _root_dir = client->GetRootDir();
                _username = client->GetUserName();
                _password = "111111";
            }

        bool Start(){
            /*
            while(1) {
                std::string *file;
                if (_client->QueuePopData((void**)&file)) {
                    printf("send file %s\n", file->c_str());
                    delete file;
                }
            }
            */
            std::string ip = _client->GetStrAddr();
            uint16_t port = atoi(_client->GetStrPort());
            CHECK_RET(_socket.Socket());
            CHECK_RET(_socket.Connect(ip, port));
            while(1) {
                switch(_cur_statu)
                {
                    case N_START:
                        CHECK_RET(LoginReq());
                        break;
                    case N_RCVLOGIN:
                        CHECK_RET(LoginRsp());
                        break;
                    case N_SNDHDR:
                        std::string *file;
                        if (_client->QueuePopData((void**)&file)) {
                            if(!SendFileHdr(*file)) {
                                printf("send file hdr error,next\n");
                                StopCurfile();
                            }
                            delete file;
                        }
                        break;
                    case N_SNDBODY:
                        if(!SendFileBody()) {
                            printf("send file body error,next\n");
                            StopCurfile();
                        }
                        break;
                    case N_SNDOVER:
                        if (!SendFileOver()) {
                            printf("recv file rsp error,next\n");
                            StopCurfile();
                        }
                        break;
                    default:
                        printf("error status:%d\n", _cur_statu);
                        return false;
                }
            }
            _socket.Close();
            return true;
        }
};
#endif
