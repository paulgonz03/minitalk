#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	print_pid(int pid)
{
	char	chr;

	if (pid > 9)
		print_pid(pid / 10);
	chr = pid % 10 + '0';
	write(1, &chr, 1);
}

void	print_char(int signal, siginfo_t *pid, void *opt)
{
	static int ch;
	static int i = 0;

	(void)opt;
	if (signal == SIGUSR1)
		ch = ch << 1 | 1;
	if (signal == SIGUSR2)
		ch = ch << 1;
	if (++i == 8)
	{
		write(1, &ch, 1);
		i = 0;
	}
	kill(pid->si_pid, SIGUSR1);
}
int main()
{
	struct sigaction sg;
    int pid;

    pid = getpid();
	print_pid(pid);
	write(1, "\n", 1);
	sg.sa_sigaction = print_char;
	sg.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sg, 0);
	sigaction(SIGUSR2, &sg, 0);
    while (1)
        pause();
}