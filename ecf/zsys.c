//
// zsys.c
// 2018/5/16
// zLimbo
//
#include "zsys.h"

void unix_error(char *msg) 
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}

void app_error(char *msg)
{
    fprintf(stderr, "%s\n", msg);
    exit(0);
}

pid_t Fork() 
{
	pid_t pid;

	if ((pid = fork()) < 0)
		unix_error("Fork error");
	return pid;
}

char* Fgets(char *ptr, int n, FILE *stream)
{
    char *rptr;

    if (((rptr = fgets(ptr, n, stream)) == NULL) && ferror(stream))
        app_error("Fget error");

    return rptr;
}

void Kill(pid_t pid, int signum)
{
    int rc;

    if ((rc = kill(pid, signum)) < 0)
    unix_error("kill error");
}

void Pause()
{
    (void)pause();
    return;
}

unsigned int Alarm(unsigned int seconds) 
{
    return alarm(seconds);
}
