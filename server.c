#include <unistd.h>
#include <stdio.h>
#include <signal.h>

// int hazesto()
// {

// }

int main()
{
    int pid;

    pid = getpid();
    printf("server PID-->%d\n", pid);
    // signal(SIGINT, hazesto());
    while (1)
    {

    }
}