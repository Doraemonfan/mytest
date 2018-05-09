#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

	struct stat sta;
	char *type, *readok;
	stat(argv[1], &sta);
	if (S_ISREG(sta.st_mode))
		type = "regular";
	else if (S_ISDIR(sta.st_mode))
		type = "directory";
	else
		type = "other";
	if ((sta.st_mode & S_IRUSR))
		readok = "yes";
	else
		readok = "no";
	printf("type: %s, read: %s\n", type, readok);

        exit(0);
}
