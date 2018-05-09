#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fd1, f2;
	fd1 = open("foo.txt", O_RDONLY, 0);
	close(fd1);
	fd2 = open("baxz.txt", O_RDONLY, 0);
	printf("fd2 = %d\n", fd2);
	exit(0);
}
