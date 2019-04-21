#include <iostream>
#include<netinet/in.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>
#include<arpa/inet.h>
#include<string.h>

using namespace std;

class TCPClient{
public:
    TCPClient(int sock = -1)
        :_sock(sock)
    {}

    int CreateSocket(){
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        client_socket.sin_family = AF_INET;
        client_socket.sin_port = htons(9000);
        inet_pton(AF_INET, "192.168.44.1", &client_socket.sin_addr);
        _sock = sock;
        return sock;
    }

    int connectSocket(){
        int ret = connect(_sock, (struct sockaddr*)&client_socket, sizeof(client_socket));
        if(ret < 0){
            perror("connect failure!!");
            return -1;
        }
        return ret;
    }

    int Getsock(){
        return _sock;
    }

    ~TCPClient(){
        if(_sock > 0){
            close(_sock);
        }
    }

private:
    int _sock;
    struct sockaddr_in client_socket;
};
int main()
{
    TCPClient client_server;
    client_server.CreateSocket();
    client_server.connectSocket();
    char buff[1024];
    memset(buff, '\0', sizeof(buff));

    while(1){
        cout << "client says:#" ;
        fgets(buff, sizeof(buff), stdin);
        buff[sizeof(buff) - 1] = '\0';
        write(client_server.Getsock(), buff, sizeof(buff));
        cout << "please wait .." << endl;
        read(client_server.Getsock(), buff, sizeof(buff));
        printf("server says: %s", buff);
    }
    return 0;
}

