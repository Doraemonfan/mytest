#include "zsys.h"
#define N 10

void sigint_handler(int sig) 
{
   //TODO 
}

unsigned snooze(unsigned secs) {
	unsigned real_secs = secs - sleep(secs);
	printf("Slept for %d of %d\n", real_secs, secs);
	return real_secs;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("format: %s <second>\n", argv[0]);
        exit(0);
    }
    int t = atoi(argv[1]);
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
        unix_error("signal error");
	snooze(t);
	exit(0);
}


