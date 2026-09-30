#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int    picoshell(char **cmds[])
{
    pid_t pid;  // for fork
    int fd[2];   // for the current pipe
    int last_fd = -1;  //to store the previous pipe' read end
   // int status;  // for wati();
    //int exit_code = 0; //final return value
    int i = 0;    // index for looping through cmds

    while(cmds[i])   // loop run until null
    {
        if(cmds[i + 1] && pipe(fd) == -1)   // create a pipe for the next command
            return 1;
        pid = fork();   //create a child process
        if(pid == -1)    //if fork fails
        {
            if(cmds[ i+ 1])  // if a pipe was created, close it
            {
                close(fd[0]);
                close(fd[1]);
            }
            return 1; // return with error
        }
        if(pid == 0)  //inside child process
        {
            if(last_fd != -1)    //if not the first command, set up input from previous pipe
            {
                if(dup2(last_fd, STDIN_FILENO) == -1)  //dup2 fails
                    exit(1);   //exit child with error
                close(last_fd);    //close the read end after duplicating
            }
            if(cmds[i + 1])   //if not the last command, set up output to the current pipe
            {
                close(fd[0]);   //close the read end of the current pipe
                if(dup2(fd[1], STDOUT_FILENO) == -1)  //dup2 fails
                    exit(1); //exit child with error
                close(fd[1]); //close the write end after duplicating
            }
            execvp(cmds[i][0], cmds[i]);  //execute the command
            exit(1); //if execvp fails, exit child with error
        }
        if(last_fd != -1)   //if not the first command, close the previous pipe's read end 
            close(last_fd);  // it's no longer needed in the parent
        if(cmds[i + 1])  // if there is a next command
        {
            close(fd[1]); // close the write end of the current pipe in the parent
            last_fd = fd[0];  // save the read end for the next command
        }
        i++;
    }
    // int last_status= 0;
    // while(wait(&status) != -1)  //wait for all child processes to finish
    //     last_status = status; 
        
    //     if ( WIFEXITED(last_status)) //check if child exited with error
    //         return WEXITSTATUS(last_status);
    //     else
    //         return 1; //if all commands succeeded, set exit_code to 0
    // return exit_code; //return 0 if all commands succeeded, 1 if any failed
    /* while (wait(&status) != -1)
    {
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
            exit_code = 1;
    }
    
    return exit_code;*/
    while(wait(NULL) > 0)
    { 
    	;
    }
    return(0);
}

/*
static int count_cmds(int argc, char **argv)
{
    int count = 1;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "|") == 0)
            count++;
    }
    return count;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (fprintf(stderr, "Usage: %s cmd1 [args] | cmd2 [args] ...\n", argv[0]), 1);

    int cmd_count = count_cmds(argc, argv);
    char ***cmds = calloc(cmd_count + 1, sizeof(char **));
    if (!cmds)
        return (perror("calloc"), 1);

    // Parsear argumentos y construir array de comandos
    int i = 1, j = 0;
    while (i < argc)
    {
        int len = 0;
        while (i + len < argc && strcmp(argv[i + len], "|") != 0)
            len++;
        
        cmds[j] = calloc(len + 1, sizeof(char *));
        if (!cmds[j])
            return (perror("calloc"), 1);
        
        for (int k = 0; k < len; k++)
            cmds[j][k] = argv[i + k];
        cmds[j][len] = NULL;
        
        i += len + 1;  // Saltar el "|"
        j++;
    }
    cmds[cmd_count] = NULL;

    int ret = picoshell(cmds);

    // Limpiar memoria
    for (int i = 0; cmds[i]; i++)
        free(cmds[i]);
    free(cmds);

    return ret;
}
*/
