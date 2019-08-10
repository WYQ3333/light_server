#ifndef __M_SRV_H__
#define __M_SRV_H__

#include "common.h"
#include "mygzip.hpp"
#include <sys/epoll.h>
#include <sys/stat.h>

#define MAX_EPOLL   1000

class Server{
    private:
        char *_root_dir;
        char *_str_addr;
        char *_str_port;
        //登陆验证线程将登陆成功后的客户端信息
        //传递给传输线程开始文件传输
        BlockQueue _login_queue;
    public:
        Server(char *root_dir, char *str_addr, char *str_port):
            _root_dir(root_dir),
            _str_addr(str_addr),
            _str_port(str_port),
            _login_queue() { }

        char *GetRootDir(){
            return _root_dir;
        }

        char *GetStrAddr(){
            return _str_addr;
        }

        char *GetStrPort(){
            return _str_port;
        }

        bool QueuePushData(void *cli){
            _login_queue.PushData(cli);
            return true;
        }

        bool QueuePopData(void **cli){
            _login_queue.PopData(cli);
            return true;
        }

        bool QueueIsEmpty(){
            return _login_queue.IsEmpty();
        }
        
        bool QueueIsFull(){
            return _login_queue.IsFull();
        }
};

class ClientInfo{
    private:
        int _cur_statu;
        int _file_fd;
        uint64_t _cur_size;
        LoginInfo _user;
        FileInfo _file;
        TcpSocket _sock;
        std::string _root_dir;
        std::string _newFile;

        bool RecvComReq(){
            return true;
        }
        //创建多级目录
        void mkdirs(char *muldir){
            int i,len;
            char str[512];    
            strncpy(str, muldir, 512);
            len=strlen(str);
            for( i=0; i<len; i++ ){
                if( str[i]=='/' ){
                    str[i] = '\0';
                    if( access(str,0)!=0 ){
                        mkdir( str, 0777 );
                    }
                    str[i]='/';
                }
            }
            if( len>0 && access(str,0)!=0 ){
                mkdir( str, 0777 );
            }
            return;
        }

        bool CreateDir(){
            char tmp[MAX_PATH] = {0};
            sprintf(tmp, "%s/%s", _root_dir.c_str(), _user.GetName());
            printf("create dir:%s\n", tmp);
            mkdirs(tmp);
            return true;
        }

        bool OpenFile(){
            char tmp[MAX_PATH] = {0};

            sprintf(tmp, "%s/%s%s", _root_dir.c_str(), _user.GetName(), _file.GetName());
            _file_fd = open(tmp, O_CREAT|O_WRONLY|O_TRUNC, 0664);
            _newFile = tmp;
            std::cout << " newFile: "<< _newFile << std::endl;

            if (_file_fd < 0) {
                printf("open file:%s error\n", tmp);
                return false;
            }
            return true;
        }

        bool WriteFile(void *buff, int len){
            if (write(_file_fd, buff, len) < 0) {
                return false;
            }
            return true;
        }

        bool CloseFile(){
            if (_file_fd >= 0) {
                close(_file_fd);
                _file_fd = -1;
                //压缩备份文件
                MyGzip gz;
                gz.beginGzip(_newFile);
                //FileCompressHuffman f;
                //f.CompressFile(_newFile);
                //删除源文件
            }
            return true;
        }

    public:
        ClientInfo(int sockfd)
            :_cur_statu(N_RCVLOGIN)
             ,_file_fd(-1)
             ,_cur_size(0)
             ,_sock(sockfd)
        {}

        ClientInfo(int sockfd, std::string path)
            :_cur_statu(N_RCVLOGIN)
            ,_file_fd(-1)
            ,_sock(sockfd)
            ,_root_dir(path)
        {}

        int GetFd(){
            return _sock.GetFd();
        }

        bool Stop(){
            CloseFile();
            _sock.Close();
        }

        bool CheckLogin(){
            CommReq req;
            if(_sock.Recv(&req, sizeof(CommReq)) < 0) {
                printf("recv com req error\n");
                return false;
            }
            printf("recv com req!!\n");
            if(!req.IsLoginReq()) {
                printf("not login req,close\n");
                return false;
            }
            if (_sock.Recv(&_user, sizeof(LoginInfo)) < 0) {
                printf("recv user info error\n");
                return false;
            }
            printf("new user login:[%s]\n", _user.GetName());
            if (!CreateDir()) {
                printf("create client dir error\n");
                return false;
            }

            CommReq rsp(RSP_LOGIN, 0);
            if (!_sock.Send((void*)&rsp, sizeof(CommReq))) {
                printf("send login rsp error\n");
                return false;
            }
            _cur_statu = N_RCVHDR;
            return true;
        }

        bool RecvFileHdr(){
            CommReq req;
            if (_sock.Recv(&req, sizeof(CommReq)) < 0) {
                printf("recv com req error\n");
                return false;
            }
            if (!req.IsUpLoadReq()) {
                printf("not up load req,close\n");
                return false;
            }
            
            if (_sock.Recv(&_file, sizeof(FileInfo)) < 0) {
                printf("recv file info error\n");
                return false;
            }
            printf("client upload file:%s\n", _file.GetName());
            CHECK_RET(OpenFile());
            std::cout << "open file 173 after " << std::endl;

            _cur_statu = N_RCVBODY;
            return true;
        }

        bool RecvFileBody(){
            char buff[1024];
            int rlen = 1024 > (_file.GetLen() - _cur_size) ? (_file.GetLen() - _cur_size):1024;
            CHECK_ERR((rlen = _sock.Recv(buff, 1024)));
            CHECK_RET(WriteFile(buff, rlen));
            _cur_size += rlen;
            if (_cur_size == _file.GetLen()) {
                _cur_statu = N_RCVOVER;
            }
            return true;
        }

        bool RecvFileOver(){
            CommReq rsp(RSP_UFILE, 0);
            CHECK_RET(_sock.Send((void*)&rsp, sizeof(CommReq)));
            _cur_statu = N_RCVHDR;
            _cur_size = 0;

            CloseFile();
            return true;
        }

        bool ClientIsTransOver(){
            return (_cur_statu == N_RCVOVER);
        }

        bool Run(){
            switch(_cur_statu){
                case N_RCVLOGIN:
                    CHECK_RET(CheckLogin());
                    break;
                case N_RCVHDR:
                    CHECK_RET(RecvFileHdr());
                    break;
                case N_RCVBODY:
                    CHECK_RET(RecvFileBody());
                    break;
                case N_RCVOVER:
                    CHECK_RET(RecvFileOver());
                    break;
                default:
                    printf("cur client trans statu error-%d\n", _cur_statu);
                    return false;
            }
            return true;
        }
};

class Epoll{
    private:
        int _epfd;
    public:
        Epoll(){
            _epfd = epoll_create(10);
        }

        ~Epoll(){
            close(_epfd);
        }

        bool Add(ClientInfo *client){
            int fd = client->GetFd();
            epoll_event ev;
            ev.data.ptr = (void*)client;
            ev.events = EPOLLIN;
            int ret = epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &ev);
            CHECK_ERR(ret);

            return true;
        }

        bool Del(int sockfd){
            int ret = epoll_ctl(_epfd, EPOLL_CTL_DEL, sockfd, NULL);
            CHECK_ERR(ret);
            return true;
        }

        bool Del(ClientInfo *client){
            int fd = client->GetFd();
            int ret = epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, NULL);
            CHECK_ERR(ret);
            return true;
        }

        bool Wait(std::vector<ClientInfo *> *list){
            int i;
            epoll_event evs[MAX_EPOLL];
            int nfds = epoll_wait(_epfd, evs, MAX_EPOLL, 1000);
            CHECK_ERR(nfds);
            for (i = 0; i < nfds; i++) {
                list->push_back((ClientInfo *)evs[i].data.ptr);
            }
            return true;
        }
};

class LoginServer{
    private:
        std::string _addr;
        int         _port;
        TcpSocket   _sock;
        Epoll       _epoll;
        Server      *_server;
        std::string _root_dir;
        std::vector<ClientInfo *> _nlogin_cli;
    public:
        LoginServer(Server *srv)
            : _server(srv){
            _addr = srv->GetStrAddr();
            _port = atoi(srv->GetStrPort());
            _root_dir = srv->GetRootDir();
        }

        bool Start(){
            int i;
            CHECK_RET(_sock.Socket());
            CHECK_RET(_sock.Bind(_addr, _port));
            CHECK_RET(_sock.Listen());
            //这里为监听socket创建客户端信息只是为了寻求结构统一
            ClientInfo lst(_sock.GetFd());
            CHECK_RET(_epoll.Add(&lst));
            while(1) {
                std::vector<ClientInfo *> _list;
                if (!_epoll.Wait(&_list)) {
                    continue;
                }
                for (i = 0; i < _list.size(); i++) {
                    if (_list[i]->GetFd() == _sock.GetFd()) {
                        TcpSocket sock;
                        if (!_sock.Accept(&sock)) {
                            continue;
                        }
                        ClientInfo *client = new ClientInfo(sock.GetFd(), _root_dir);
                        _epoll.Add(client);
                        _nlogin_cli.push_back(client);
                    }else {
                        if (!_list[i]->Run()) {
                            _epoll.Del(_list[i]);
                            _list[i]->Stop();
                            for (auto it = _nlogin_cli.begin(); it != _nlogin_cli.end(); ) {
                                if (*it == _list[i]) {
                                    printf("login failed delete client!!\n");
                                    _nlogin_cli.erase(it);
                                }
                            }
                            delete _list[i];
                        }else {
                            //从当前epoll移除，
                            _epoll.Del(_list[i]);
                            for (auto it = _nlogin_cli.begin(); it != _nlogin_cli.end(); ) {
                                if (*it == _list[i]) {
                                    printf("delete client from no login vector!!\n");
                                    _nlogin_cli.erase(it);
                                }
                            }
                            //将客户端信息添加到队列，传输线程获取后开始传输文件
                            printf("insert client to trans thread!!\n");
                            _server->QueuePushData((void*)_list[i]);
                        }
                    }
                }
            }
            return true;
        }
};

class TransServer{
    private:
        Server *_server;
        Epoll _epoll;
    public:
        TransServer(Server *srv):_server(srv) {}

        bool Start(){
            int i = 0;
            while(1) {
                while(!_server->QueueIsEmpty()) {
                    ClientInfo *client;
                    _server->QueuePopData((void**)&client);
                    _epoll.Add(client);
                    printf("new client start trans!!\n");
                }
                std::vector<ClientInfo *> _trans_cli;
                if (!_epoll.Wait(&_trans_cli)) {
                    continue;
                }
                for (i = 0; i < _trans_cli.size(); i++) {
                    if (!_trans_cli[i]->Run()) {
                        _epoll.Del(_trans_cli[i]);
                        _trans_cli[i]->Stop();
                        for (auto it = _trans_cli.begin(); it != _trans_cli.end(); ) {
                            if (*it == _trans_cli[i]) {
                                printf("trans file failed delete client!!\n");
                                delete _trans_cli[i];
                                _trans_cli.erase(it);
                            }
                        }
                    }
                    if (_trans_cli[i]->ClientIsTransOver()) {
                        _trans_cli[i]->Run();
                    }
                }
            }
            return true;
        }
};

#endif
