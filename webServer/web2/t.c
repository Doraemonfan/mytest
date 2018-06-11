#include <stdio.h>
#include <stdlib.h>
#include "znet.h"
#include "rio.h"

int main(int argc, int argv[]) 
{
	int n;
	rio_t rio;
	char buf[MAXLINE];
	rio_readinitb(&rio, STDIN_FILENO);
	while ((n = rio_readlineb(&rio, buf, MAXLINE)) != 0)
		rio_writen(STDOUT_FILENO, buf, n);
}
