#pragma once
#include <iostream>
#include <unistd.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <string.h>

#define MAX_CON 10

class tcpsocket{
public:
    int Socket();
    int Bind(int sockfd, std::string ip_addr, uint16_t port);
    int Listen(int sockfd);
    int Connect(int sockfd, const std::string ip_addr, uint16_t port);
    int Accept(int sockfd, std::string& client, uint16_t& port);
    int Recv(int sockfd, char *buf, int len);
    int Send(int sockfd, char *data, int len);
    int Close(int sockfd);
};

int tcpsocket::Socket(){
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        return -1;
    }
    return sockfd;
}

int tcpsocket::Bind(int sockfd, std::string ip_addr, uint16_t port){
    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = inet_addr(ip_addr.c_str());
    socklen_t len = sizeof(struct sockaddr_in);
    int ret = bind(sockfd, (struct sockaddr*)&sock_addr, len);
    if(ret < 0){
        return -1;
    }
    return 0;
}

int tcpsocket::Listen(int sockfd){
    int ret = listen(sockfd, MAX_CON);
    if(ret < 0){
        return -1;
    }
    return 0;
}

int tcpsocket::Connect(int sockfd, const std::string ip_addr, uint16_t port){
    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port);
    client_addr.sin_addr.s_addr = inet_addr(ip_addr.c_str());
    socklen_t len = sizeof(struct sockaddr_in);
    int ret = connect(sockfd, (struct sockaddr*)&client_addr, len);
    if(ret < 0){
        return -1;
    }
    return 0;
}


int tcpsocket::Accept(int sockfd, std::string& client, uint16_t& port){
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(struct sockaddr_in);
    int ret = accept(sockfd, (struct sockaddr*)&client_addr, &len);
    if(ret < 0){
        return -1;
    }
    //将十进制整数转化为点分十进制的字符串
    client = inet_ntoa(client_addr.sin_addr);
    //将网络的端口号转化为主机字节序
    port = ntohs(client_addr.sin_port);
    return ret;
}

int tcpsocket::Recv(int sockfd, char *buf, int len){
    int ret = recv(sockfd, buf, len, 0);
    if (ret < 0) {
        printf("recv error\n");
        return -1;
    }else if (ret == 0) {
        printf("connect shutdown\n");
        return -1;
    }
    return ret;
}

int tcpsocket::Send(int sockfd, char *data, int len){
    int ret = send(sockfd, data, len, 0);
    if(ret < 0){
        return -1;
    }
    return ret;
}

int tcpsocket::Close(int sockfd){
    int ret = close(sockfd);
    return ret;
}
