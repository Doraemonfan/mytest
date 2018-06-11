#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n) 
{
	size_t nleft = n;
	ssize_t nread;
	char *bufp = usrbuf;
	
	while (nleft > 0) {
		if ((nread = rio_read(rp, bufp, nleft)) < 0)
			return -1;
		else if (nread == 0)
			break;
		nleft -= nread;
		bufp += nread;
	}
	return (n - nleft);
}
