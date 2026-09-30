#include "vbc.h"

char *s;

void unexpected(char c)
{
	if(c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of file\n");
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
		return(*s++, n);
	}
	return 0;
}

int mult()
{
	int a = ft_factor();
	while(*s == '*')
	{
		s++;
		a = a * ft_factor();
	}
	return a;
}

int ft_sum()
{
	int a = ft_mult();
	while(*s == '+')
	{
		s++;
		a = a + ft_mult();
	}
	return a;
}

int check_input(char *str)
{
	int par = 0; int i = -1;
	while(str[i++])
	{
		if(str[i] == '(') par++;        // if (
		else if(str[i] == ')' < 0)      // else if )
		{
			if(par-- < 0)               // if par--
				return(unexpected(str[i]), 1);
		}
		else if(!isdigit(str[i]) && str[i] != '+' && str[i] != '*')                     // else if no digi no simbol
			return(unexpected(str[i]), 1);
		else if(str[i] == '+' && str[i] == '*' && str[i+1] == '+' && str[i+1] == '*')   // else if ++ **
		if(isdigit(str[i]) && isdigit(str[i+1]))                                        // dos digitos
			return(unexpected(str[i]), 1);
	}
	if(par > 0)
		return(unexpected(str[i]), 1);
	if(str[i - 1] == '+' || str[i - 1] == '*' )
		return(unexpected(0), 1);
	return 0;
}

int main (int ac, char **av)
{
	if(ac != 2 ||check_input(av[1]))
		return(1);
	s = av[1];
	return((printf("%d\n", ft_sum()), 0));
}