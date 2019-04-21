#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<strings.h>
#include<string.h>
#include<errno.h>

#define SERVER_PORT 9000
#define SERVER_IP "192.168.0.111"

int main(){
    char buf[1024];
    memset(buf, '\0', sizeof(buf));

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_sock;
    bzero(&server_sock, sizeof(server_sock));
    server_sock.sin_family = AF_INET;
    server_sock.sin_port = htons(SERVER_PORT);

    int ret = connect(sock, (struct sockaddr*)&server_sock, sizeof(server_sock));
    if(ret < 0){
        printf("connect faild ..., errno is: %d \n", errno);
        return 1;
    }

    printf("connect success : \n");

    while(1){
        printf("cilent : # ");
        fgets(buf, sizeof(buf), stdin);
        buf[strlen(buf) - 1] = '\0';
        write(sock, buf, sizeof(buf));
        if(strncasecmp(buf, "quit", 4)){
            printf("quit\n");
            break;
        }
        printf("please wait ...\n");
        read(sock, buf, sizeof(buf));
        printf("server : %s\n", buf);
    }
    close(sock);
    return 0;
}
