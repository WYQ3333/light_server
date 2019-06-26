#include "tcpsocket.hpp"
#define CHECK(q) if((q) < 0){return -1;}

int main()
{
    tcpsocket client;
    int client_sockfd = client.Socket();
    CHECK(client_sockfd);
    CHECK(client.Connect(client_sockfd, "172.17.19.145", 9000));
    while(true){
        char buff[1024] = {0};
        std::cout << "client says: " ;
        fgets(buff, 1024, stdin);
        std::cout << buff << std::endl;
        client.Send(client_sockfd, buff, 1024);
        /* write(client_sockfd, buff, 1024); */
        std::cout << "client send massage finish!!!" << std::endl;
        memset(buff, 0x00, 1024);
        client.Recv(client_sockfd, buff, 1024);
        //read(client_sockfd, buff, 1024);
        std::cout << "server says: " << buff << std::endl;
    }
    client.Close(client_sockfd);
    return 0;
}

