#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putnbr(int n, int base)
{
	char	digit[17] = "0123456789abcdef";
	int		count;

	count = 0;
	if (n > (base - 1))
		ft_putnbr(n / base, base);
	count += write(1, &digit[n % base], 1);
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		d;
	int		x;
	char	*s;
	int		count;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (fmt && *fmt == '%')
		{
			count++;
			fmt++;
			if (*fmt == 's')
			{
				s = va_arg(ap, char *);
				if (s == NULL)
				{
					count += write(1, "(null)", 6);
					count--;
				}
				else
					while (s && *s)
						count += write(1, s++, 1);
			}
			else if (*fmt == 'd')
			{
				d = va_arg(ap, int);
				count += ft_putnbr(d, 10);
			}
			else if (*fmt == 'x')
			{
				x = va_arg(ap, int);
				count += ft_putnbr(x, 16);
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

int	main(void)
{
	char	*ptr;

	ptr = NULL;
	ft_printf("%d\n", ft_printf("%s ", ptr));
	printf("%d\n", printf("%s ", ptr));
	ft_printf("%d\n", ft_printf("%d ", 52)); // count = 3 -> 5; 2; \n;
	printf("%d\n", printf("%d ", 52));       // count = 3 -> 5; 2; \n;
	ft_printf("%x\n", 9);
	printf("%x\n", 9);
	ft_printf("%s\n", "");
	printf("%s\n", "");
	ft_printf("Magic %s is %d", NULL, 42);
	printf("Magic %s is %d", "", 42);
	ft_printf("Hexadecimal for %d is %x\n", '0', 42);
	ft_printf("%s\n", "I love watermelons");
	ft_printf("%p\n", 42);
	ft_printf("%s\n", NULL);
	ft_printf("");
	ft_printf("%%\n");
	ft_printf("Magic %s is %d\n", "number", 31);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	/* 	ft_printf("%d\n", ft_printf("ft = *+Ç!=?¿!"));
		// OJO!!
		// los caracteres especiales los BUFFERiza de uno en uno y tarda la hostia
		// se mezclan los bufferes de un printf anterior que no haya terminado
		printf("%d\n", printf("st = *+Ç!=?¿!")); */
}
