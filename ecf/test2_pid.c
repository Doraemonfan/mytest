#include "zsys.h"
#define N 4

int main() {
    pid_t pid[N];
    for (int i = 0; i < N; ++i)
        if ((pid[i] = Fork()) == 0)
            exit(100 + i);
    int i = 0, status;
    pid_t retpid;
    while ((retpid = waitpid(pid[i++], &status, 0)) > 0) {
        if (WIFEXITED(status))
            printf("child %d terminated normally with exit\
                    status=%d\n", retpid, WEXITSTATUS(status));
        else
            printf("child %d terminated abnormally\n", retpid);
    }

    if (errno != ECHILD)
        unix_error("waitpid error");
    
    exit(0);
}
        
        
