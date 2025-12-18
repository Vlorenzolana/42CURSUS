#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

//static pid_t child_pid;

void alarm_handler(int sig)
{
    (void)sig;
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
    struct sigaction sa;
    pid_t pid;
    int status;

    sa.sa_handler = alarm_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGALRM, &sa, NULL);

    pid = fork();
    if(pid == -1)
        return (-1);
    if( pid == 0)
    {
        f();
        exit(0);
    }
   // child_pid = pid;
    alarm(timeout);
    if(waitpid(pid, &status, 0) == -1)
    {
        if(errno == EINTR)
        {
            kill(pid, SIGKILL);
            waitpid(pid, NULL, 0);
            if(verbose)
                printf("Bad function: timed out after %u seconds\n", timeout);
            return(0);
        }
        return (-1);
    }
    if(WIFEXITED(status))
    {
        if(WEXITSTATUS(status) == 0)
        {
            if(verbose)
                printf("Nice function!\n");
            return (1);
        }
        else
        {
            if(verbose)
                printf("Bad function: exited with code %d\n", WEXITSTATUS(status));
            return (0);
        }
    }
    if(WIFSIGNALED(status))
    {
        if(verbose)
            printf("Bad function: %s\n", strsignal(WTERMSIG(status)));
        return(0);
    }
    return (-1);
}
