#include <stdlib.h>

int	ft_abs(nbr)
{
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

int	nlen(nbr)
{
	int	len;

	len = 0;
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	if (nbr < 0)
		i++;
	nbr = ft_abs(nbr);
	len = nlen(nbr) + i;
	str = malloc(sizeof(char *) * len + 1);
	if (!str)
		return(NULL);
	str[0] = '-';
	str[len] = '\0';
	while (--len >= i)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
#include <stdio.h>
/* 
int	main(void)
{
	int		nbr;
	char	*res;

	nbr = -1234;
	printf("%d\n", nbr);
	res = ft_itoa(nbr);
	printf("%s\n", res);
	free(res);
	return (0);
}
 */