#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

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
// void ft_send_signal(char *sentence)
// {
//     int i;
    
//     i = 0;
//     while ()
//     {

//     }
// }

int main(int argc, char **argv)
{
    int error;
    int pid;

    if (argc != 3)
        return (printf("Error parametres\n"), 1);
    else
    {
        printf("%s\n", argv[1]);
        if (!ft_parser_pid(argv[1]))
            return(printf("error parserPID"), 1);
        pid = atoi(argv[1]);
        
        ft_send_signal (argv[2], pid);

    }
    return(0);
}
