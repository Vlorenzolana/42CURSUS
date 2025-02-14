#include <unistd.h>

int	main(int ac, char **av)
{
	unsigned char	seen[256] = {0};
	int				i;
	int				j;

	if (ac == 3)
	{
		i = 0;
		j = 0;
		while (av[1][i])
		{
			if (!seen[(unsigned char)av[1][i]])
			{
				write(1, &av[1][i], 1);
				seen[(unsigned char)av[1][i]] = 1;
			}
			i++;
		}
		while (av[2][j])
		{
			if (!seen[(unsigned char)av[2][j]])
			{
				write(1, &av[2][j], 1);
				seen[(unsigned char)av[2][j]] = 1;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
#include <unistd.h>

void	ft_print_string_a(char *string_a)
{
	int	i;
	int	j;

	if (!string_a)
		return ;
	i = 0;
	write(1, &string_a[i++], 1);
	while (string_a[i])
	{
		j = 0;
		while (i >= j)
		{
			if (string_a[i] == string_a[j])
				break ;
			j++;
		}
		if (j == i)
			write(1, &string_a[i], 1);
		i++;
	}
}
void	ft_print_string_b(char *string_a, char *string_b)
{
	int	i;
	int	j;

	i = 0;
	while (string_b[i] != '\0')
	{
		j = 0;
		while (string_a[j] && string_b[i] != string_a[j])
			j++;
		if (string_b[i] == string_a[j])
		{
			i++;
			continue ;
		}
		j = 0;
		while (i > j)
		{
			if (string_b[i] == string_b[j])
			{
				i++;
				continue ;
			}
			j++;
		}
		write(1, &string_b[i], 1);
		i++;
	}
}
void	ft_union(char *string_a, char *string_b)
{
	if (string_a && !string_b)
		ft_print_string_a(string_a);
	else if (!string_a && string_b)
		ft_print_string_a(string_b);
	else if (!string_a && !string_b)
		return ;
	else
	{
		ft_print_string_a(string_a);
		ft_print_string_b(string_a, string_b);
	}
}
int	main(void)
{
	char    *string_a = "HELLO HOW ARE YOU";
	char    *string_b = "OLAKEASE SI SI BIEN GRASIAS";
	ft_union(string_a, string_b);
	return (0);
} */