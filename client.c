#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int g_confirm;

int ft_parser_pid(char *pid)
{
    int i;

    i = 0;
    while (pid[i])
    {
        if (pid[i] >= '0' && pid[i] <= '9')
            i++;
        else
            return(0);
    }
    return(i);
}

void ft_send_signal(char ch, int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		g_confirm = 0;
		if (ch >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_confirm != 1)
			pause();
	}
}

void	sig_usr_handler(int signal)
{
	(void)signal;
	g_confirm = 1;
}

int main(int argc, char **argv)
{
    int pid;
    int i = 0;

    if (argc != 3)
        return (printf("Error parametres\n"), 1);
    else
    {
        if (!ft_parser_pid(argv[1]))
            return(printf("error parserPID\n"), 1);
        pid = atoi(argv[1]);
        if (pid <= 0)
            return(0);
        signal(SIGUSR1, &sig_usr_handler);
  	    while (argv[2][i])
        {
		    ft_send_signal(argv[2][i], pid);
            i++;
        }
    }
    return(0);
}
