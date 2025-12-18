#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	picoshell(char ***cmds);

int	main(int argc, char **argv)
{
	int		ncmds;
	char	***cmds;
	int		k;
	int		start;
	int		ret;

	if (argc < 2)
	{
		fprintf(stderr, "usage: %s cmd1 '|' cmd2 '|' ...\n", argv[0]);
		return (1);
	}
	// contar comandos
	ncmds = 1;
	for (int i = 1; i < argc; i++)
		if (strcmp(argv[i], "|") == 0)
			ncmds++;
	// reservar cmds
	cmds = (char ***)malloc((ncmds + 1) * sizeof(char **));
	if (!cmds)
	{
		perror("malloc");
		return (1);
	}
	// partir argv por '|'
	k = 0;
	start = 1;
	for (int i = 1; i < argc; i++)
	{
		if (strcmp(argv[i], "|") == 0)
		{
			argv[i] = NULL;           // termina el argv del comando anterior
			cmds[k++] = &argv[start]; // inicio de ese comando
			start = i + 1;            // siguiente comando empieza tras '|'
		}
	}
	cmds[k++] = &argv[start]; // último comando
	cmds[k] = NULL;
	ret = picoshell(cmds);
	free(cmds);
	return (ret);
}

/*
gcc - Wall - Wextra - Werror picoshell.c main.c -
	o picoshell

#Ejemplo 1
			./
		picoshell / bin / ls "|" / usr / bin /
		grep picoshell

#Ejemplo 2
			./
		picoshell echo "squalala"
						"|" cat "|" sed 's/a/b/g'
*/
