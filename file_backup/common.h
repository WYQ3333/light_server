#ifndef __M_COM_H__
#define __M_COM_H__
#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define CHECK_RET(exp) if(!(exp)){\
    return false;\
}
#define CHECK_ERR(exp) if((exp) < (0)){\
    perror("");\
    return false;\
}
#define MAX_PATH 256
#define MAX_BUFF 10240
#define QUEUE_NUM   1000

enum _req_type_t
{
    REQ_LOGIN = 1,  //登陆请求
    RSP_LOGIN,      //登陆成功/失败回复
    REQ_UFILE,      //上传文件请求
    RSP_UFILE,      //上传文件完毕/失败回复
    REQ_DFILE,      //下载文件请求
    RSP_DFILE,      //下载文件完毕/失败回复
};
enum _trans_status_t
{
    N_START = 1,    //准备开始接收/发送网络请求
    N_STOP,         //准备停止关闭客户端
    N_RCVLOGIN,     //准备接收登陆请求
    N_RCVHDR,       //准备开始接收文件头信息
    N_RCVBODY,      //准备接收文件数据体
    N_RCVOVER,      //文件接收完毕，
    N_SNDLOGIN,     //准备发送登陆请求
    N_SNDHDR,       //准备开始发送文件头信息
    N_SNDBODY,      //准备发送文件数据体
    N_SNDOVER,      //文件发送完毕，
};



class FileInfo
{
    private:
        uint64_t _flen;
        char _fname[MAX_PATH];
    public:
        FileInfo():_flen{-1}, _fname({0}) { }
        FileInfo(std::string &fname, uint64_t len)
        {
            _flen = len;
            strncpy(_fname, fname.c_str(), MAX_PATH);
        }
        char *GetName()
        {
            return _fname;
        }
        uint64_t GetLen()
        {
            return _flen;
        }
};
class LoginInfo
{
    private:
        char _uname[32];
        char _upass[32];
    public:
        LoginInfo():_uname({0}), _upass({0}) { }
        LoginInfo(std::string &uname, std::string &upass)
        { 
            strncpy(_uname, uname.c_str(), 32);
            strncpy(_upass, upass.c_str(), 32);
        }
        char *GetName()
        {
            return _uname;
        }
        char *GetPass()
        {
            return _upass;
        }
};
class CommReq
{
    private:
        uint8_t _type;
        uint64_t _len;
    public:
        CommReq():_type(0), _len(0) { }
        CommReq(uint8_t type, uint64_t len):_type(type), _len(len) { }
        uint8_t GetType()
        {
            return _type;
        }
        uint64_t GetLen()
        {
            return _len;
        }
        bool IsLoginReq()
        {
            return (_type == REQ_LOGIN);
        }
        bool IsLoginRsp()
        {
            return (_type == RSP_LOGIN);
        }
        bool IsUpLoadReq()//客户端上传文件请求
        {
            return (_type == REQ_UFILE);
        }
        bool IsUpLoadRsp()//客户端上传文件请求
        {
            return (_type == RSP_UFILE);
        }
        bool IsDownLoadReq()//客户端下载文件请求
        {
            return (_type == REQ_DFILE);
        }
        bool IsDownLoadRsp()
        {
            return (_type == RSP_DFILE);
        }
};

class TcpSocket
{
    private:
        int fd;
        bool SetNonBlock()
        {
            fcntl(fd, F_SETFL, O_NONBLOCK | fcntl(fd, F_GETFL, 0));
            return true;
        }
        bool KeepAlive(int idle = 30, int interval = 3, int count = 10)
        {
            int ret;
            int keepalive = 1;  //打开tcp保活机制
            //int keepidle = 30;  //空闲30秒无数据则开始探测
            //int keepintval = 3; //每隔3秒探测一次
            //int keepcount = 10; //探测10次均无响应则认定连接断开
            CHECK_ERR(setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE,
                        (void*)&keepalive, sizeof(int)));
            CHECK_ERR(setsockopt(fd, SOL_TCP, TCP_KEEPIDLE, 
                        (void*)&idle, sizeof(int)));
            CHECK_ERR(setsockopt(fd, SOL_TCP, TCP_KEEPINTVL, 
                        (void*)&interval, sizeof(int)));
            CHECK_ERR(setsockopt(fd, SOL_TCP, TCP_KEEPCNT, 
                        (void*)&count, sizeof(int)));
            return true;
        }
        bool ReusedAddr()
        {
            int option = 1;
            CHECK_ERR(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,
                        (void*)&option, sizeof(int)));
            return true;
        }
    public:
        TcpSocket():fd(-1) { }
        TcpSocket(int sockfd):fd(sockfd) { }
        int GetFd()
        {
            return fd;
        }
        bool Socket()
        {
            fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            CHECK_ERR(fd);
            ReusedAddr();
            KeepAlive();
            return true;
        }
        bool Close()
        {
            close(fd);
            return true;
        }
        bool Bind(std::string &ip, int port)
        {
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(ip.c_str());
            socklen_t len = sizeof(struct sockaddr_in);
            CHECK_ERR(bind(fd, (struct sockaddr*)&addr, len));
            return true;
        }
        bool Connect(std::string &ip, int port)
        {
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(ip.c_str());
            socklen_t len = sizeof(struct sockaddr_in);
            CHECK_ERR(connect(fd, (struct sockaddr*)&addr, len));
            return true;
        }
        bool Listen(int num = 5)
        {
            CHECK_ERR(listen(fd, num));
            return true;
        }
        bool Accept(TcpSocket *peer, std::string *ip = NULL, uint16_t *port = NULL)
        {
            int new_fd;
            struct sockaddr_in peer_addr;
            socklen_t len = sizeof(struct sockaddr_in);
            new_fd = accept(fd, (struct sockaddr*)&peer_addr, &len);
            CHECK_ERR(new_fd);
            peer->fd = new_fd;
            if (ip) {
                *ip = inet_ntoa(peer_addr.sin_addr);
            }
            if (port) {
                *port = ntohs(peer_addr.sin_port);
            }
            return true;
        }
        ssize_t Recv(void *buff, int len)
        {
            int rlen = 0;
            rlen = recv(fd, buff, len, 0);
            if (rlen < 0) {
                if (errno == EAGAIN || errno == EINTR) {
                    return 0;
                }
                perror("recv error");
                return -1;
            }else if (rlen == 0) {
                printf("peer shutdown\n");
                return -1;
            }

            return rlen;
        }
        bool Send(void *buff, int len)
        {
            int slen = 0;
            int alen = 0;
            while(alen < len) {
                slen = send(fd, (char*)buff + alen, len - alen, 0);
                if (slen < 0) {
                    if (errno == EAGAIN || errno == EINTR) {
                        continue;
                    }
                    perror("send error");
                    return false;
                }
                alen += slen;
            }

            return true;
        }

};
class BlockQueue{
    private:
        std::queue<void *> q;
        int cap;
        pthread_mutex_t lock;
        pthread_cond_t full;
        pthread_cond_t empty;

    private:
        void LockQueue()
        {
            pthread_mutex_lock(&lock);
        }
        void UnLockQueue()
        {
            pthread_mutex_unlock(&lock);
        }
        void ProductWait()
        {
            pthread_cond_wait(&full, &lock);
        }
        void ConsumeWait()
        {
            pthread_cond_wait(&empty, &lock);
        }
        void NotifyProduct()
        {
            pthread_cond_signal(&full);
        }
        void NotifyConsume()
        {
            pthread_cond_signal(&empty);
        }

    public:
        bool IsEmpty()
        {
            return ( q.size() == 0 ? true : false );
        }
        bool IsFull()
        {
            return ( q.size() == cap ? true : false );
        }
        BlockQueue(int _cap = QUEUE_NUM):cap(_cap)
        {
            pthread_mutex_init(&lock, NULL);
            pthread_cond_init(&full, NULL);
            pthread_cond_init(&empty, NULL);
        }
        void PushData(void *data)
        {
            LockQueue();
            while(IsFull()){
                NotifyConsume();
                ProductWait();
            }
            q.push(data);
            NotifyConsume();
            UnLockQueue();
        }
        void PopData(void **data)
        {
            LockQueue();
            while(IsEmpty()){
                NotifyProduct();
                ConsumeWait();
            }
            *data = q.front();
            q.pop();
            NotifyProduct();
            UnLockQueue();
        }
        ~BlockQueue()
        {
            pthread_mutex_destroy(&lock);
            pthread_cond_destroy(&full);
            pthread_cond_destroy(&empty);
        }
};


#endif
