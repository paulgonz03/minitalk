#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int ft_parser_pid(char *pid)
{
    int i;

    i = 0;
    while (pid[i])
    {
        if (pid[i] >= '0' || pid[i] <= '9')
            i++;
        else
            return(0);
        if (i > 4)
            return(0);
    }
    return(i);
}
// void ft_send_signal(char *sentence)
// {
//     int i;
//     int binary;

//     i = 0;
//     while (sentence[i])
//         i++;
//     binary = malloc(i*8 + 1);
//     while (sentence[i])
//     {

//     }
// }

int main(int argc, char **argv)
{
    int error;
    int pid;

    if (argc != 3)
    {
        printf("Error parametres\n");
        return (1);
    }
    else
    {
        if (!ft_parser_pid(argv[1]))
            return(printf("error parserPID"), 1);
        pid = atoi(argv[1]);  
    
    }
    return(0);
}
