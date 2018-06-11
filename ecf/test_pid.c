#include "zsys.h"
#define N 10

int main() {
	
	for (int i = 0; i < N; ++i)
		if (Fork() == 0) 
			exit(100 + i);

	int status;
	pid_t pid;
	while ((pid = waitpid(-1, &status, 0)) > 0) {
		if (WIFEXITED(status)) 
			printf("child %d terminated normal "  
				"with exit status=%d\n",
					pid, WEXITSTATUS(status));
		else
			printf("child %d terminated abnormal", pid);
	}

	if (pid != ECHILD)
		unix_error("waitpid error");

	exit(0);
}
