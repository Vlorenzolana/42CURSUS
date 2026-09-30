/* Allowed functions: pipe, fork, dup2, execvp, close, exit
write the following function:

	int    ft_popen(const char file, charconst argv[], char type)

The function must launch the executable file with the arguments argv (using execvp).
If the type is 'r' the function must return a file descriptor connected to the output of the command.
If the type is 'w' the function must return a file descriptor connected to the input of the command.
In case of error or invalid parameter the function must return -1.

example:

int main() {
	int fd = ft_popen("ls", (char const[]){"ls", NULL}, 'r');

	charline;
	while(line = get_next_line(fd))
		ft_putstr(line);
}

Hint: Do not leak file descriptors! */
/* 
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int ft_popen(const char *file, char *const av[], int type)
{
	if(!file || !av || ( type != 'r' && type != 'w' ))
		return -1;
	int fd[2];
	if(pipe(fd) < 0)
		return -1;
	pid_t pid = fork();
	if(pid < 0)
	{
		close(fd[1]);
		close(fd[0]);
		return (-1);
	}
	if(pid == 0)
	{
		if(type == 'r')
		{
			close(fd[0]);
			if(dup2(fd[1], STDOUT_FILENO) < 0)
				exit(-1);
		}
		else
		{
			close(fd[1]);
			if(dup2(fd[0], STDIN_FILENO) < 0)
				exit(-1);
		}
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
		close(fd[0]);
		return(fd[1]);
	}
}
 */
/* int main()
{
	int fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');
	char buf[1];
	while(read(fd, buf, 1))
		write(1, buf, 1);
	close(fd);
	return (0);
} */
/* #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], int type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return(-1);
	int fd[2];
	if(pipe(fd) < 0)
		return(-1);
	int pid = fork();
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
			close(fd[0]);
			if(dup2(fd[1], 1) < 0)
				exit(-1);
		}
		else
		{
			close(fd[1]);
			if(dup2(fd[0], 0) < 0)
				exit(-1);
		}
		execvp(file, argv);
		exit(-1);
	}
	if(type == 'r')
	{
		close(fd[1]);
		return(fd[0]);
	}
	close(fd[0]);
	return(fd[1]);
} */
/* 
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int ft_popen(const char *file, char *const argv[], char type)
{
	if(!file || !argv || (type != 'r' && type != 'w'))
		return -1;
	int fd[2];
	if(pipe(fd))
		return -1;
	int pid = fork();
	if(pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return -1;
	}
	if(pid == 0)
	{
		if(type == 'r')
		{
			close(fd[0]);
			if(dup2(fd[1], 1) < 0)
				exit(-1);
			close(fd[1]);
		}
		else{
			close(fd[1]);
			if(dup2(fd[0], 0) < 0)
				exit(-1);
			close(fd[0]);
		}
		execvp(file, argv);
		exit(-1);
	}
	else{
		if(type == 'r')
		{
			close(fd[1]);
			return(fd[0]);
		}
		else{
			close(fd[0]);
			return(fd[1]);
		}
	}
	return 0;
} */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int ft_popen(const char *file, char *const argv[], char type)
{
    if (!file || !argv || (type != 'r' && type != 'w')) {
               return -1;
           }
           int pipefd[2];
           pid_t cpid;        

           if (pipe(pipefd) == -1) 
               return -1;

           cpid = fork();
           if (cpid == -1) {
               close(pipefd[1]);
               close(pipefd[0]);
               return -1;
           }

           if (cpid == 0) {    /* Child reads from pipe */
                close(type == 'r' ? pipefd[0] : pipefd[1]);
                if(dup2(type == 'r' ? pipefd[1] : pipefd[0], type == 'r' ? 1 : 0))
                    exit (-1);
                close(type == 'r' ? pipefd[1] : pipefd[0]);
                execvp(file, argv);
                exit (-1);
           } else {            /* Parent writes argv[1] to pipe */
               close(type == 'r' ? pipefd[1] : pipefd[0]);
               return(type == 'r' ? pipefd[0] : pipefd[1]);
           }
           return 0;
       }
