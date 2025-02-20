#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int g_confirm;

int ft_parser_pid(char *pid)
{
    int i;

    i = 0;
    while (pid[i])
    {
        if (pid[i] >= '0' && pid[i] <= '9'&& i < 5)
            i++;
        else
            return(0);
    }
    return(i);
}
void ft_send_signal(char *sentence, int pid)
{
    int i;
    int binary;

    binary = 8;
    i = 0;
    while (sentence[i])
    {
        if (sentence[i] >> i & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i++;
        binary--;
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

    if (argc != 3)
        return (printf("Error parametres\n"), 1);
    else
    {
        printf("%s\n", argv[1]);
        if (!ft_parser_pid(argv[1]))
            return(printf("error parserPID"), 1);
        pid = atoi(argv[1]);
        if (pid < 0)
            return(0);
        signal (SIGUSR1, &sig_usr_handler);
        ft_send_signal (argv[2], pid);
    }
    return(0);
}
