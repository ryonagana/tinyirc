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


    return 0;

}
