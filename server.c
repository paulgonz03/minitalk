#include <unistd.h>
#include <stdio.h>
#include <signal.h>
void	ft_print_char(int signal, siginfo_t *pid, void *opt)
{
	static int	i;
	static int	chr;

	(void)opt;
	if (signal == SIGUSR1)
		chr = chr << 1 | 1;
	else
		chr = chr << 1;
	if (++i == 8)
	{
		write(1, &chr, 1);
		i = 0;
		chr = 0;
	}
	kill(pid->si_pid, SIGUSR1);
}
int main()
{
    struct sigaction sg;
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