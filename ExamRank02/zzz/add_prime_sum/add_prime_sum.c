#include <unistd.h>

int is_prime(int nbr)
{
	int n;

	if (nbr < 2)
        	return 0;
	
	n = 2;
	while(n <= nbr/2)
	{
		if(nbr % n == 0)
			return(1);
		n++;
	}
	return(0);
}

int ft_atoi(char *s)
{
	int num;

	num = 0;
	while(s && *s)
	{
		num = (num * 10) + (*s - '0');
		++s;
	}
	return(num);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int n)
{
	char digit;
	if(n > 9)
		ft_putnbr(n/10);
	digit = (n % 10) + '0';
	ft_putchar(digit);
}

int main(int ac, char ** av)
{
	int i;
	int res;
	int number;
       
	i = 2;
	res = 0;
	number = ft_atoi(av[1]);
	if(ac == 2 && number > 0)
	{
		while(i <= number)
		{
			if(is_prime(i))
				res += i;
			i++;
		}
		ft_putnbr(res);
	}
	write(1, "\n", 1);
	return(0);
}
