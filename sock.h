#ifndef SOCK_HEADER
#define SOCK_HEADER




int sock_start();
int send_message(int fd, const char *msg,...);
int sock_connect(int sock_fd, const char* ip, int portnum);
long unsigned int sock_recv(int fd, char* data, size_t size);

void sock_end(int fd);

#endif
