#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "sock.h"

int sock_start()
{
    int fd = -1;

    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        return -1;
    }
    return fd;
}

int send_message(int fd, const char* msg, ...)
{
    va_list lst;
    int bytes = 0;
    va_start(lst,msg);
    char buf[1024] = {0};
    bytes = vsnprintf(buf,1024-1,msg,lst);
    va_end(lst);

    *(buf+bytes+1) = '\r';
    *(buf+bytes+2) = '\n';

    bytes += 2;

    int l = 0;
    if((l=send(fd, buf,bytes,0)) < 0){
        perror("send_message()");
        return -1;
    }

    return 0;

}


int sock_connect(int sock_fd, const char* ip, int portnum)
{
    struct sockaddr_in s;
    char address[255] = {0};
    int connected = -1;

    strncpy(address,ip, 255);
    s.sin_addr.s_addr = inet_addr(address);
    s.sin_family = AF_INET;
    s.sin_port = htons(portnum);

    if((connected = connect(sock_fd,(struct sockaddr*)&s, sizeof(struct sockaddr))) < 0)
    {
            perror("connect()");
            return -1;
    }

    return 0;

}

long unsigned int sock_recv(int fd, char *data, size_t size)
{
    int bytes_recv;

    if(fd < 0 || data == NULL){
        return -1;
    }
    bytes_recv = recv(fd, data,  size,0);
    return bytes_recv;

}


void sock_end(int fd)
{
    if(fd < 0) return;
    close(fd);
}
