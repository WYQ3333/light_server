#include <iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
using namespace std;


class TCPServer{
public:
    TCPServer(int sock = -1)
        :_sock(sock)
    {}

    int CreateSock(){
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        server_sock.sin_family = AF_INET;
        server_sock.sin_port = htons(9000);
        //inet_pton(AF_INET,INADDR_ANY, &server_sock.sin_addr);
        server_sock.sin_addr.s_addr = htonl(INADDR_ANY);
        _sock = sock;
        return sock;
    }

    int bindSock(){
        int ret = bind(_sock, (struct sockaddr*)&server_sock, sizeof(struct sockaddr_in));
        if(ret < 0){
            perror("bind failure");
            return -1;
        }
        return ret;
    }

    int listenSock(){
        int ret = listen(_sock, 10);
        if(ret < 0){
            perror("listen failure : ");
            return -1;
        }
        return ret;
    }

    ~TCPServer(){
        if(_sock > 0){
            close(_sock);
        }
    }


private:
    int _sock;
    struct sockaddr_in server_sock;
};

int main()
{
    TCPServer server_socket;
    server_socket.CreateSock();
    server_socket.bindSock();
    cout << "listen ing..." << endl;
    return 0;
}

