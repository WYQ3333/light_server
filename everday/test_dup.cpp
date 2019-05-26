#include <iostream>
#include<unistd.h>
#include<errno.h>
#include<stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main()
{
    char buf[1024]= {'I',' ', 'l','o','v','e', ' ', 'y','o', 'u','\n'};
    int fd = open("1.txt", O_WRONLY|O_CREAT|O_APPEND, 0666);
    write(fd, buf, 1024);
    write(fd, buf, 1024);
    write(fd, buf, 1024);
    write(fd, buf, 1024);
    write(fd, buf, 1024);
    dup2(fd, 1);
    cout << "向标准输出写相当于写入了文件！！！" << endl;
    close(fd);
    return 0;
}

