
/*
Subject
Assignment name : union Expected files : union.c Allowed functions : write
--------------------------------------------------------------------------------
Write a program that takes two strings and displays,
without doubles,the characters that appear in either one of the strings.

The display will be in the order characters appear in the command line,
and will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example :
$ >./union "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padintoqefwjy$
$ >./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$ >./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$
>./ union | cat - e $ $ > $ >./ union "rien" | cat -e
$
$ >
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int j;
	char seen[256] = {0};
	i = 0;
	j = 0;

	if (ac == 3)
	{
		while (av[1][i])
		{
			if (!seen[(unsigned char)av[1][i]])
			{
				seen[(unsigned char)av[1][i]] = 1;
				write(1, &av[1][i], 1);
			}
			i++;
		}
		while (av[2][j])
		{
			if (!seen[(unsigned char)av[2][j]])
			{
				seen[(unsigned char)av[1][i]] = 1;
				write(1, &av[2][j], 1);
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
