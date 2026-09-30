#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sched.h>

int ft_popen(const char *file, char *const av[], int type)
{
    if(!file || !av || (type != ' r ' || type != 'w'))
        return (-1);

    int fd[2];
    if(pipe(fd) < 0 )
        return(-1);
    pid_t pid = fork();
    if(pid < 0)
    {
        close(fd[0]);
        close(fd[1]);
        return(-1);
    }
    if(pid == 0)
    {
        if(type == 'r')
        {

        }
        else
        {

        }
        close(fd[0]);
        close(fd[1]);
        execvp(file, av);
        exit(-1);
    }
    if(type == 'r')
    {
        close(fd[1]);
        return(fd[0]);
    }
    else
    {
        close
    }
}