#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void Usage(){
    printf("usage: ./client [ip] [port]\n");
}

int main(int argc, char* argv[])
{
    if(argc != 3){
        Usage();
        return 1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0 ){
        perror("socket error");
        return 1;
    }
    int ret = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
    if(ret < 0){
        perror("connect");
        return 1;
    }
    while(true){
        printf(">");
        fflush(stdout);

        char buf[1024] = {0};
        read(0, buf, sizeof(buf) - 1);
         ssize_t write_size = write(fd, buf, strlen(buf));
         if(write_size < 0){
             perror("write");
             continue;
         }

         ssize_t read_size = read(fd, buf, sizeof(buf) - 1);
         if(read_size < 0){
             perror("read");
             continue;
         }

         if(read_size == 0){
             printf("server close\n");
             break;
         }

         printf("server say: %s", buf);
    }
    close(fd);
    return 0;
}

