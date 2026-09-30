#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return(-1);
	int fd[2];
	if(pipe(fd) < 0)
		return (-1);
	int pid = fork();
	if(pid < 0)
	{
		if(fd[1] != 0)
		{
			close(fd[0]);
			close(fd[1]);
		}
		return(-1);
	}
	if(pid == 0)
	{
		if(type == 'r')
		{
			close(fd[0]);
			if(dup2(fd[1], 1) < 0)
				return(-1);
			close(fd[1]);
		}
		else{
			close(fd[1]);
			if(dup2(fd[0], 0) < 0)
				return(-1);
			close(fd[0]);
		}
		execvp(file, argv);
		exit(-1);
	}
	else
	{
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
}

int main()
{
	// int fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');
	// int fd = ft_popen("ls", (char *const[]){"ls", "-1", "/tmp", NULL}, 'r');
	// write(fd, "line one\n", 9);
    // write(fd, "line two\n", 9);
	// int fd = ft_popen("cat", (char *const[]){"cat", "-e", NULL}, 'w');
	int fd = ft_popen("grep", (char *const[]){"grep", "-i", "HELLO", NULL}, 'w');
    write(fd, "Hello World\n", 12);
	write(fd, "goodbye\n", 8);
    write(fd, "HELLO!\n", 7);
	// int fd = ft_popen("grep", (char *const[]){"grep", "-c", "int", "ft_popen4.c", NULL}, 'r');
	int fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');
	char buf[1];
	while(read(fd, buf, 1) > 0)
		write(1, buf, 1);
	close(fd);
	return (0);
}