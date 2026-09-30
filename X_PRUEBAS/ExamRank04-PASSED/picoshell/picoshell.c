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
				pipefd[0];
				pipefd[1];
		   }   
           cpid = fork();
           if (cpid == -1) {
				close(pipefd[0]);
				close(pipefd[1]);
               exit (1);
           }

           if (cpid == 0) {    /* Child reads from pipe */
               if(pipefd[1])
			   	{
					close(pipefd[0] != -1);
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

int main()
{
	char **cmds[] = {(char *[]){"ls, NULL"}, (char *[]){"grep", "picoshell", NULL},NULL};
	return(picoshell(cmds));
}