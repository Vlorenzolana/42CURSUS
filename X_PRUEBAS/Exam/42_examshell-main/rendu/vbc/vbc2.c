#include "vbc.h"

char *s;

int unexpected(char c)
{
	if(c)
		return(printf("Unexpected char '%c'\n", c));
	else
		return(printf("Unexpected end of file\n"));
}

int ft_factor(void)
{
	int n;
	if(isdigit(*s))
		return(*s++ - '0');
	if(*s == '(')
	{
		s++;
		n = ft_sum();
		return(s++, n);
	}
	return(0);
}

int ft_mul(void)
{
	int a = ft_factor();
	while(*s == '*')
	{
		s++;
		a = a * ft_factor();
	}
	return a;
}

int ft_sum(void)
{
	int a = ft_mul();
	while(*s == '+')
	{
		s++;
		a = a + ft_mul();
	}
	return a;
}

int check_input (char *str)
{
	int par = 0; int i = -1;
	while (str[++i])
	{
		if(str[i] == '(') par++;
		else if (str[i] == ')')
		{
			if(par-- < 0 )
				return(unexpected(str[i]), 1);
		}
		else if(!isdigit(str[i]) && str[i] != '+' && str[i] != '*')
			return(unexpected(str[i]), 1);
		if(isdigit(str[i]) && isdigit(str[i+1]))
			return(unexpected(str[i]), 1);
	}
	if(par != 0)
		return(unexpected(par > 0 ? '(' : ')'), 1);
	if(str[i -1] == '+' || str[i -1 ] == '*')
		return(unexpected(0), 1);
	return(0);
}

int main (int argc, char **argv)
{
	if(argc != 2 || check_input(argv[1]))
		return(1);
	s = argv[1];
	return(printf("%d\n", ft_sum()), 0);
}