#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(long n, int base, int *count) // We call count by ref. &count
{
	char digit[16] = "0123456789abcdef";
	if (n < 0)
	{
		*count += write(1, "-", 1);
		n *= -1;
	}
	if (n >= (base))
		ft_putnbr(n / base, base, count);
	*count += write(1, &digit[n % base], 1);
}

int	ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		d;
	char	*s;
	long	x;

	va_start(ap, fmt);
	count = -1;
	while (*fmt)
	{
		if (fmt && *fmt == '%')
		{
			++count;
			fmt++;
			if (*fmt == 's')
			{
				s = va_arg(ap, char *);
				if (s == NULL)
					count += write(1, "(null)", 6);
				else
					while (s && *s)
						count += write(1, s++, 1);
			}
			else if (*fmt == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d, 10, &count);
			}
			else if (*fmt == 'x')
			{
				x = va_arg(ap, unsigned int);
				ft_putnbr(x, 16, &count);
			}
			else
			{
				count += write(1, "%", 1);
				count += write(1, fmt, 1);
			}
		}
		else
			count += write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (count);
}

#include <limits.h>

int	main(void)
{
	char	*ptr;
	char	*c;

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
	printf("STD Hexadecimal for %d is %x\n", 2147483647, 2147483647);
/* 	printf("STD Hexadecimal for %d is %x\n", -2147483648, -2147483648);
	//PRINTF FAILS, INT MIN HEX & DECIMAL IMPOSSIBLE TO PRINT, ALAS NOT TESTED */
	ft_printf("\n");
	ft_printf("\n");
		printf("STD  Hexadecimal for %d is %x\n", 2147483647, 2147483647);
		printf("STD  Hexadecimal for %ld is %lx\n", -2147483647,
			-2147483647);
	ft_printf("MIARD %d\n", ft_printf("%s ", c));
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
	ft_printf("\n");
	ft_printf("%d\n", ft_printf("ft = *+Ç!=?¿!"));
	// OJO!!
	// los caracteres especiales los BUFFERiza de uno en uno y tarda la hostia
	// se mezclan los bufferes de un printf anterior que no haya terminado
	printf("%d\n", printf("st = *+Ç!=?¿!"));
}
