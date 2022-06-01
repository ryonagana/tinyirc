#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#include "sock.h"

#define UNUSED_VAR(v) ((void)v)

int main(int argc, char *argv[])
{
    UNUSED_VAR(argc);
    UNUSED_VAR(argv);

    int sock = sock_start();

    if(sock < 0){
        perror("sock error");
        return 1;
    }

    if(sock_connect(sock, "130.185.232.126", 6667)< 0)
    {
        perror("connect error");
    }
    char buf[1024] = {0};

    send_message(sock,"NICK tikabot");
    send_message(sock,"USER tikabot 0 * :Mr. Archdark");


    while(sock_recv(sock, buf, 1024-1)){
        printf("%s", buf);
    }

    sock_end(sock);



    /*
    int socket_desc = 0;
    struct sockaddr_in irc;

    char buffer[2048] = {0};
    int connect_status = -1;
    int line = 0;
    int bytes_read = 0;

    socket_desc = socket(AF_INET, SOCK_STREAM,0);


    if(socket_desc < 0){
        printf("Couldn't Create a Socket!");
        exit(-1);
    }

    irc.sin_addr.s_addr = inet_addr("130.185.232.126");
    irc.sin_family = AF_INET;
    irc.sin_port = htons(6667);

    connect_status=connect(socket_desc, (struct sockaddr*)&irc, sizeof(irc));

    if(connect_status == -1){
        perror("Error:");
        printf("Connect Status: %d", connect_status);
        return -1;
    }


    printf("Connected!");

    //snprintf(buffer, sizeof(buffer), "PASS\r\n");
    //send(socket_desc, buffer, sizeof(buffer)-1,0);
    memset(buffer,0,sizeof(buffer));
    bytes_read = sprintf(buffer,"NICK cbtikabot\r\n");
    send(socket_desc, buffer, bytes_read,0);
    memset(buffer,0,sizeof(buffer));
    bytes_read= sprintf(buffer, "USER tikacbot 0 * :Mr Archdark\r\n");
    send(socket_desc, buffer, bytes_read,0);



    while((line = recv(socket_desc,buffer,sizeof(buffer),0) > 0)){
        fprintf(stdout, "SERVER: %s", buffer);
    }


    close(socket_desc);

    return 0;
    */


}
