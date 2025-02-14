#include <unistd.h>

int main (int ac, char ** av)
{
	int i;
	int word;
	
	if(ac == 2)
	{
		i = 0;
		word = 0;
		while(av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
			i++;
		while(av[1][i])
		{
			if (av[1][i] != ' ' &&  av[1][i] != '\t')
			{
				word = 1;
				write(1, &av[1][i], 1);
			}
			else if (word)
                        {
				write(1, " ", 1);
				word = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return(0);
}

