//
// zsys.h
// 2018/5/16
// zLimbo
//

#ifndef __Z_SYS_H__
#define __Z_SYS_H__

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

// function declarations

void unix_error(char *msg);
void app_error(char *msg);
pid_t Fork();
char* Fgets(char *ptr, int n, FILE *stream);
void Kill(pid_t pid, int signum);
void Pause();
unsigned int Alarm(unsigned int seconds);


#endif  // zsys.h
