#include "vbc.h"

char *s;

int unexpected(char c)
{
	if(c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of file\n");
	return 1;
}

int ft_factor(void)
{
	int n;
	if(isdigit(*s))
		return (*s++ - '0');
	if(*s == '(')
	{
		s++;
		n = ft_sum();
		return(s++, n);
	}
	return 0;
}

int ft_sum(void)
{
	int a = ft_factor(), op;
	while((op = *s) == '+' || op == '*')
	{
		s++;
		a = (op == '+') ? a + ft_factor() : a * ft_factor();
	}
	return a;
}

int check_input(char *str) 
{
	int par = 0, i = -1;

	while(str[++i])
	{
		if(str[i] == '(')
			par++;
		else if(str[i] == ')')
		{
			if(par-- < 0)
				return(unexpected(str[i]), 1);
		}
		else if(!isdigit(str[i]) && str[i] != '+' && str[i] != '*')
			return(unexpected(str[i]), 1);
		if(isdigit(str[i]) && isdigit(str[i+1]))
			return(unexpected(str[i]), 1);
	}
	if(par != 0)
		return(unexpected(par > 0 ? '(' : ')'), 1);
	if(str[i-1] == '+' || str[i-1] == '*')
		return(unexpected(0), 1);
	return 0;
}

int main (int ac, char **av)
{
	if(ac != 2 || check_input(av[1]))
		return 1;
	s = av[1];
	return(printf("'%d'\n", ft_sum()), 0);
}