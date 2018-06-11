//
// zSocket.h
// 2018/5/9
//

#ifndef __Z_SOCKET_H__
#define __Z_SOCKET_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define __USE_XOPEN2K
#include <netdb.h>

#define MAXLINE 8192
#define LISTENQ 1024
#define MAXBUF 8192

typedef struct sockaddr SA;

#define RIO_BUFSIZE 8192
typedef struct {
	int rio_fd;
	int rio_cnt;
	char *rio_bufptr;
	char rio_buf[RIO_BUFSIZE];
} rio_t;

ssize_t rio_readn(int fd, void *usrbuf, size_t n);
ssize_t rio_writen(int fd, void *usrbuf, size_t n);
void rio_readinitb(rio_t *rp, int fd);
static ssize_t rio_read(rio_t *rp, char *usrbuf, size_t n);
ssize_t rio_readlineb(rio_t *rp, void *usrbuf, size_t maxlen);
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);

int open_clientfd(char *hostname, char *port);
int open_listenfd(char *port);
#endif // zSocket.h
