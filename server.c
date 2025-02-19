#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main()
{
    struct sigaction;
    int pid;

    pid = getpid();
    printf("server PID-->%d\n", pid);
    while (1)
        pause();
}