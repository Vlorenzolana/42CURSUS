#include <stdio.h>
#include <stdlib.h>

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (!s2)
		return (NULL);
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	int		wc;
	char	**out;

	i = 0;
	j = 0;
	k = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wc++;
		while (str[i] && (str[i]) != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	out = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		j = i;
		while (str[i] && (str[i]) != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
		if (i > j)
		{
			out[k] = (char *)malloc(sizeof(char) * (i - j + 1));
			if (!out)
				return (NULL);
			out[k] = ft_strncpy(out[k], &str[j], (i - j + 1));
			k++;
		}
	}
	out[k] = NULL;
	return (out);
}

void	ft_free(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	main(int ac, char **av)
{
	int i = 0;

	if (ac != 2)
		return (0);
	
	printf("Original string is : %s\n", av[1]);

	char **split = ft_split(av[1]);

	if (!split)
	{
		ft_free(split);
		return (0);
	}
	printf("After split \n");
	while (split[i])
		printf("%s\n", split[i++]);
	ft_free(split);
	return (0);
}