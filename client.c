#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void    send_string(pid_t pid, char c)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if ((c >> i) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(100); // delais signaux server 100
        i++;
    }
}
int main(int ac, char **av)
{
    if (ac == 3)
    {
        int i = 0;
        pid_t pid = atoi(av[1]);
        char *str = av[2];

        while (str[i])
        {
            send_string(pid, str[i]);
            i++;
        }
        send_string(pid, '\0');
        return(0);
    }
    write(1, "Error arguments missing\n", 25);
    return(1);
}
