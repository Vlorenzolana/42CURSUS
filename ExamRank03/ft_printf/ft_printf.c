#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putnbr(int d, int base)
{
	char	digit[16] = "0123456789abcdef";

	if (d > (base - 1))
		ft_putnbr((d / base), base);
	write(1, &digit[d % base], 1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		d;
	int		x;
	char	*s;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (fmt && *fmt == 's')
			{
				s = va_arg(ap, char *);
				while (s && *s)
					write(1, s++, 1);
			}
			else if (fmt && *fmt == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d, 10);
			}
			else if (fmt && *fmt == 'x')
			{
				x = va_arg(ap, int);
				ft_putnbr(x, 16);
			}
			else
			{
				write(1, "%", 1);
				write(1, fmt, 1);
			}
		}
		else
			write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (1);
}
int	main(void)
{
	ft_printf("%s\n", "toto");
	ft_printf("%p\n", 42);
	ft_printf("%s\n", NULL);
	ft_printf("");
	ft_printf("%%\n");
	ft_printf("Magic %s is %d\n", "number", 31);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}

/*
if (*fmt == '%')
{
	fmt++;
	switch (*fmt)
	{
	case 's':
		s = va_arg(ap, char *);
		while (s && *s)
			write(1, s++, 1);
		break ;
	case 'd':
		d = va_arg(ap, int);
		ft_putnbr(d, 10);
		break ;
	case 'x':
		x = va_arg(ap, int);
		ft_putnbr(x, 16);
		break ;
	default:
		write(1, "%", 1);
		write(1, fmt, 1);
		break ;
} */