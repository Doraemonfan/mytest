#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void rio_readinitb(rio_t *rp, int fd) 
{
	rp->rio_fd = fd;
	rp->rio_cnt = 0;
	rp->rio_bufptr = rp->rio_buf;
}
