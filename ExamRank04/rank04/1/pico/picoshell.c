/* Assignment name:    picoshell
Expected files:        picoshell.c
Allowed functions:    close, fork, wait, exit, execvp, dup2, pipe
___

Write the following function:

int    picoshell(char *cmds[]);

The goal of this function is to execute a pipeline. It must execute each
commands [sic] of cmds and connect the output of one to the input of the
next command (just like a shell).

Cmds contains a null-terminated list of valid commands. Each rows [sic]
of cmds are an argv array directly usable for a call to execvp. The first
arguments [sic] of each command is the command name or path and can be passed
directly as the first argument of execvp.

If any error occur [sic], The function must return 1 (you must of course
close all the open fds before). otherwise the function must wait all child
processes and return 0. You will find in this directory a file main.c which
contain [sic] something to help you test your function.


Examples: 
./picoshell /bin/ls "|" /usr/bin/grep picoshell
picoshell
./picoshell echo 'squalala' "|" cat "|" sed 's/a/b/g'
squblblb/
*/

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int picoshell(char **cmds[])
{
    int i = 0;
    int fd[2];
    int in_fd = 0;   // stdin par défaut (0)
    int ret = 0;
    pid_t pid;
    int status;

    while (cmds[i])
    {
        if (cmds[i + 1]) // Si ce n’est pas la dernière commande
        {
            if (pipe(fd) == -1)
                return 1;
        }
        else
        {
            fd[0] = -1;
            fd[1] = -1;
        }

        pid = fork();
        if (pid < 0)
        {
            if (fd[0] != -1)
                close(fd[0]);
            if (fd[1] != -1)
                close(fd[1]);
            if (in_fd != 0)
                close(in_fd);
            return 1;
        }
        if (pid == 0) // Enfant
        {
            if (in_fd != 0)
            {
                if (dup2(in_fd, 0) == -1)
                    exit(1);
                close(in_fd);
            }
            if (fd[1] != -1) // si ce n'est pas le dernier
            {
                if (dup2(fd[1], 1) == -1)
                    exit(1);
                close(fd[1]);
                close(fd[0]);
            }
            execvp(cmds[i][0], cmds[i]);
            exit(1); // execvp échoué
        }
        else // Parent
        {
            if (in_fd != 0)
                close(in_fd);
            if (fd[1] != -1)
                close(fd[1]);
            in_fd = fd[0];
            i++;
        }
    }

    while (wait(&status) > 0)
    {
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            ret = 1;
        else if (!WIFEXITED(status))
            ret = 1;
    }

    return ret;
}
