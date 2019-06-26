#include "tcpsocket.hpp"
#define CHECK(q) if((q) < 0){return -1;}

int main()
{
    tcpsocket server;
    int server_sockfd = server.Socket();
    CHECK(server_sockfd);
    CHECK(server.Bind(server_sockfd, "172.17.19.145", 9000));
    CHECK(server.Listen(server_sockfd));
    while(true){
        std::string client_ip;
        uint16_t client_port;
        int client_sockfd = server.Accept(server_sockfd, client_ip, client_port);
        if(client_sockfd < 0){
            continue;
        }
        std::cout << "new connect: " << "[ip->" << client_ip << " port->" << htons(client_port) << "]" << std::endl;
        while(true){
            char buff[1024] = {0};
            server.Recv(client_sockfd, buff, 1024);
            std::cout << "client says: " << buff << std::endl;
            memset(buff, 0x00, 1024);
            std::cout << "server says: ";
            fgets(buff, 1024, stdin);
            server.Send(client_sockfd, buff, strlen(buff));
            std::cout << "please wait ..." << std::endl;
        }
    }
    server.Close(server_sockfd);
    return 0;
}

