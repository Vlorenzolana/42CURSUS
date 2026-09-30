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
				exit -1;
			close(fd[1]);
		}
		else{
			close(fd[1]);
			if(dup2(fd[0], 0) < 0)
				exit -1;
			close(fd[0]);
		}
		execvp(file, argv);
		exit -1;
	}
	if(type == 'r')
	{
		close(fd[1]);
		return(fd[0]);
	}
		close(fd[0]);
		return(fd[1]);

	return 0;
}