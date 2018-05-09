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
#include <unistd.h>

#define __USE_XOPEN2K
#include <netdb.h>

#define MAXLINE 8192
#define LISTENQ 1024
#define MAXBUF 8192

#define RIO_BUFSIZE 8192
typedef struct {
	int rio_fd;
	int rio_cnt;
	char *rio_bufptr;
	char rio_buf[RIO_BUFSIZE];
} rio_t;

#endif // zSocket.h
