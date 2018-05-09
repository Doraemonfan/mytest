#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[]) {
	DIR* streamp;
	struct dirent *dep;
	streamp = opendir(argv[1]);
	errno = 0;
	while ((dep = readdir(streamp)) != NULL) {
		printf("Found file: %s\n", dep->d_name);
	}
	if (errno != 0)
		strerror("readdir error");
	closedir(streamp);
	exit(0);
}

