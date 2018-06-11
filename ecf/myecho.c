#include "zsys.h"

int main(int argc, char **argv, char **envp) 
{
    printf("Command-ine arguments:\n");
    char **ap = argv;
    int i = 0;
    while (*ap != NULL) 
        printf("    argv[%2d]: %s\n", i++, *(ap++));

    printf("Environment variables:\n");
    char **ep = envp;
    i = 0;
    while (*ep != NULL)
        printf("    envp[%2d]: %s\n", i++, *(ep++));

    exit(0);
}

