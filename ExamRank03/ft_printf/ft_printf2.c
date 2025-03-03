#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c, int *counter)
{
	counter += write(1, &c, 1);
}

void	ft_putstr(char *str, int *counter)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		*counter += write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(long n, int *counter)
{
	int	result;

	if (n < INT_MIN || n > INT_MAX)
		return ;
	if (n < 0)
	{
		*counter += write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		result = n + '0';
		*counter += write(1, &result, 1);
	}
	else
	{
		result = (n % 10) + '0';
		ft_putnbr(n / 10, counter);
		*counter += write(1, &result, 1);
	}
}

void	ft_puthex(long n, int *counter)
{
	char	*alpha;
	char	result;

	alpha = "abcedf";
	if (n < 0)
	{
		*counter += write(1, "-", 1);
		n *= -1;
	}
	if (n < 16)
	{
		if (n <= 9)
		{
			result = n + '0';
			*counter += write(1, &result, 1);
		}
		else
		{
			result = alpha[n - 9 - 1];
			*counter += write(1, &result, 1);
		}
	}
	else
	{
		ft_puthex(n / 16, counter);
		if (n % 16 < 10)
		{
			result = n + '0';
			*counter += write(1, &result, 1);
		}
		else
		{
			result = alpha[(n % 16) - 9 - 1];
			*counter += write(1, &result, 1);
		}
	}
}

void	ft_flags(char c, va_list args, int *counter)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (c == 'd')
		ft_putnbr(va_arg(args, int), counter);
	else if (c == 'x')
		ft_puthex(va_arg(args, int), counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		counter;

	va_start(args, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
				counter += write(1, "%", 1);
			else
				ft_flags(s[i + 1], args, &counter);
			i += 2;
		}
		else
		{
			counter += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(args);
	return (1);
}

#include <limits.h>

int	main(void)
{
	char *ptr;
	char *c;

	c = NULL;
	ptr = NULL;
	ft_printf("FT  Hexadecimal for %d is %x\n", 42, 42);
	ft_printf("FT  Hexadecimal for %d is %x\n", -42, 42);
	ft_printf("\n");
	ft_printf("\n");
	printf("STD  Hexadecimal for %d is %x\n", 42, 42);
	printf("STD  Hexadecimal for %d is %x\n", -42, 42);
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("FT  Hexadecimal for %d is %x\n", 2147483647, 2147483647);
	ft_printf("FT  Hexadecimal for %d is %x\n", -2147483647, -2147483647);
	ft_printf("\n");
	ft_printf("\n");
	printf("STD  Hexadecimal for %d is %x\n", 2147483647, 2147483647);
	printf("STD  Hexadecimal for %d is %x\n", -2147483647, -2147483647);
	/* 	ft_printf("MIARD %d\n", ft_printf("%s ", c));
		printf("STDRD %d\n", printf("%s ", c));
		ft_printf("\n");
		ft_printf("%d\n", ft_printf("%s ", ptr));
		printf("%d\n", printf("%s ", ptr));
		ft_printf("\n");
		ft_printf("MIARD %d\n", ft_printf("%d ", 5265476));
		printf("STDRD %d\n", printf("%d ", 5265476));
		ft_printf("\n");
		sleep(1 / 2);
		ft_printf("MIARD %d\n", ft_printf("%x ", 33));
		printf("STDRD %d\n", printf("%x ", 33));
		sleep(1 / 2);
		ft_printf("\n");
		ft_printf("%x\n", 9);
		printf("%x\n", 9);
		ft_printf("\n");
		ft_printf("%s\n", "");
		printf("%s\n", "");
		ft_printf("\n");
		ft_printf("Magic %s is %d\n", NULL, 42);
		printf("Magic %s is %d\n", "", 42);
		ft_printf("\n");
		ft_printf("Hexadecimal for %d is %x\n", '0', 42);
		ft_printf("%d\n", ft_printf("%s\n", "I love watermelons"));
		printf("%d\n", printf("%s\n", "I love watermelons"));
		ft_printf("\n");
		ft_printf("%p\n", 42);
		ft_printf("%s\n", NULL);
		ft_printf("");
		ft_printf("%%\n");
		ft_printf("\n");
		ft_printf("Magic %s is %d\n", "number", 42);
		printf("Magic %s is %d\n", "number", 42);
		ft_printf("\n");
		ft_printf("Hexadecimal for %d is %x\n", 42, 42);
		printf("Magic %s is %d\n", "number", 42);
		ft_printf("\n"); */
	/*  ft_printf("%d\n", ft_printf("ft = *+Ç!=?¿!"));
		// OJO!!
		// los caracteres especiales los BUFFERiza de uno en uno y tarda la hostia
		// se mezclan los bufferes de un printf anterior que no haya terminado
		printf("%d\n", printf("st = *+Ç!=?¿!")); */
}