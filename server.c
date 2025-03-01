#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	ft_print_char(int signal, siginfo_t *pid, void *opt)
{
	static int ch;
	static int i = 0;

	(void)opt;
	if (signal == SIGUSR1)
		ch = ch << 1 | 1;
	if (signal == SIGUSR2)
		ch = ch << 1;
	if (++i == 8)
		i = write(1, &ch, 1) - 1;
	kill(pid->si_pid, SIGUSR1);
	
}
int main()
{
	struct sigaction	sg;
    int pid;

    pid = getpid();
    printf("server PID-->%d\n", pid);
	sg.sa_sigaction = ft_print_char;
	sg.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sg, 0);
	sigaction(SIGUSR2, &sg, 0);
    while (1)
        pause();
}