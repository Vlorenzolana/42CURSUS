/* #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/wait.h>

int picoshell(char **cmds[])
{
	int fd[2]; int i = 0; int in_fd = -1; int pid;
	while(cmds[i])
	{
		if(cmds[i+1])
		{ 
			if(pipe(fd) < 0)
			return(1);
		}
		else
		{
			fd[0] = -1;
			fd[1] = -1;
		}
		pid = fork();
		if(pid < 0)
		{
			if(fd[1] != -1)
			{
				close(fd[0]);
				close(fd[1]);
			}
			if(in_fd != -1)
			{
				close(in_fd);
			}
			return(1);
		}
		if(pid == 0)
		{
			if(fd[1] != -1)
			{
				close(fd[0]);
				if(dup2(fd[1], 1) < 0)
					exit(1);
				close(fd[1]);
			}
			if(in_fd != -1)
			{
				if(dup2(in_fd, 0) < 0)
					exit(1);
			    close(in_fd);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		else
		{
			if(in_fd != -1)
				close(in_fd);
			if(fd[1] != -1)
				close(fd[1]);
			in_fd = fd[0];
		}
		i++;
	}
	while(wait(NULL) > 0)
		;
	return(0);
} */

/* int main(void)
{
	char **cmds[] = {(char *[]){"ls", NULL}, (char *[]){"grep", "picoshell", NULL}, NULL};
	return(picoshell(cmds));
} */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int picoshell(char **cmds[])
{
	int pipefd[2]; int cpid; int in_fd = -1; int i = -1; 
	while(cmds[++i])
	{
		if (cmds[i+1]) {
               if(pipe(pipefd) >0)
			   	return 1;
           }
		   else{
				pipefd[0] = -1;
				pipefd[1] = -1;
		   }   
           cpid = fork();
           if (cpid < 0) {
				 if(pipefd[1] != -1)
			   	{
					pipefd[0] = -1;
					pipefd[1] = -1;
				}
				if(in_fd != -1)
			   	{
					close(in_fd);
				}
               exit (1);
           }

           if (cpid == 0) {    /* Child reads from pipe */
               if(pipefd[1] != -1)
			   	{
					close(pipefd[0]);
					if( dup2(pipefd[1], 1)< 0)
						exit (1);
					close(pipefd[1]);
				}
				if(in_fd != -1)
			   	{
					close(pipefd[1]);
					if( dup2(in_fd, 0)< 0)
						exit (1);
					close(in_fd);
				}
			execvp(cmds[i][0], cmds[i]);
			exit (-1);
           } else {            /* Parent writes argv[1] to pipe */
            if(in_fd != -1)
			   	{
					close(in_fd);
				}    
			if(pipefd[1] != -1)
			   	{
					close(pipefd[1]);
				}
				in_fd = pipefd[0];
           }
	}
	while(wait(NULL)>0)
		;
	return 0;

}

/* int main(void)
{
	char **cmds[] = {(char *[]){"ls", NULL}, (char *[]){"grep", "picoshell", NULL}, NULL};
	return(picoshell(cmds));
} */