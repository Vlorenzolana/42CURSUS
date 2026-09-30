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

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sched.h>

int ft_popen(const char *file, char *const av[], int type)
{
	if(!file || !av || (type != 'r' && type !='w' ))
		return -1;

	int fd[2];
	if (pipe(fd) < 0)
		return -1;
	pid_t pid = fork(); // fork() crea una copia exacta del proceso actual y devuelve:
	if (pid < 0) {
		close(fd[1]);
		close(fd[0]);
		return -1;
	}
	if(pid == 0) 
	{
		if(type == 'r')
		{
			close(fd[0]);
			if(dup2(fd[1], STDOUT_FILENO) < 0) //duplica fd[1] en STDOUT_FILENO(1), redirige la salida estándar al extremo de escritura del pipe y cierra el oldfd(fd[1]).
				exit (-1);
		}
		else
		{
			close(fd[1]);
			if(dup2(fd[0], STDIN_FILENO) < 0) //duplica fd[0] en STDIN_FILENO(0), redirige la entrada estándar al extremo de lectura del pipe y cierra oldfd(fd[0])..
				exit (-1);
		}
		close(fd[0]);
		// fd[0] = 0;
		// close(fd[0]); // ñapaaaaaa para cerrar fd 0's tantas veces como te de la gana
		close(fd[1]);
		execvp(file, av); // execvp(file, av) ejecuta el programa especificado por file con los argumentos av. Si execvp falla, se devuelve -1.
		exit (-1);
	}
	if (type == 'r') // Si el tipo es 'r', el padre cierra el extremo de escritura del pipe y devuelve el extremo de lectura para que el programa pueda leer la salida del comando.
	{
		close(fd[1]);
		return (fd[0]);
	}
	else { // Si el tipo es 'w', el padre cierra el extremo de lectura del pipe y devuelve el extremo de escritura para que el programa pueda escribir en la entrada del comando.
		close(fd[0]);
		return (fd[1]);
	}
}

/*#include <stdio.h>
#include <string.h>
int main()
{
	//int fd = open("texte", O_RDONLY);
	int fd = ft_popen("ls", (char *const[]){"ls", NULL}, 'r');

	char buf[1];
	while(read(fd, buf, 1))
		write(1, buf, 1);

	close(fd);
	return (0);
}*/ 