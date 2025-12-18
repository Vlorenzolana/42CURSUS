/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:33:47 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	find_print(const char *str, int i, int len, va_list list)
{
	void	*ptr;

	if (!str)
		len = print_str("(null)", len);
	if (str[i] == '%')
		len = print_char('%', len);
	if (str[i] == 'c')
		len = print_char(va_arg(list, int), len);
	if (str[i] == 's')
		len = print_str(va_arg(list, char *), len);
	if ((str[i] == 'd') || (str[i] == 'i'))
		len = print_number(va_arg(list, int), len);
	if (str[i] == 'u')
		len = print_positive_number(va_arg(list, int), len);
	if (str[i] == 'x')
		len = print_hex(va_arg(list, unsigned int), len, 'x');
	if (str[i] == 'X')
		len = print_hex(va_arg(list, unsigned int), len, 'X');
	if (str[i] == 'p')
	{
		ptr = va_arg(list, void *);
		len = ft_print_pointer(ptr, len);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	i = 0;
	len = 0;
	va_start(arg, str);
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			len = print_char(str[i], len);
		}
		else
		{
			len = find_print(str, i + 1, len, arg);
			i++;
		}
		i++;
	}
	va_end(arg);
	return (len);
}

/* int main ()
{
//variables

	int	number = 123;
	int	cero_number = 0;
	int negative_number = -123;
	int	hexadecimal_number = 1000;
	int	negative_hexadecimal_number = -1000;
	int	min_number = -2147483648;
	int	max_number = 2147483647;
	unsigned int	unsigned_number = 123;
	char simple_char = '0';
	char especial_char = '@';
	char *string = "Hola Mundo";	
	char *empty_string = "";
	void *pointer = NULL;
	char *NULL_string = NULL;



	//original printf
	printf("Original Printf:\n");
	printf("\n");

	printf("= %i\n", number);
	printf("= %i\n", cero_number);
	printf("= %i\n", negative_number);
	printf("= %i\n", min_number);
	printf("= %d\n", max_number);
	printf("= %u\n", unsigned_number);
	printf("= %x\n", hexadecimal_number);
	printf("= %x\n", negative_hexadecimal_number);
	printf("= %X\n", hexadecimal_number);
	printf("= %X\n", negative_hexadecimal_number);
	printf("= %c\n", simple_char);
	printf("= %c\n", especial_char);
	printf("= %s\n", string);
	printf("= %s\n", empty_string);
	printf("= %p\n", pointer);
	printf("= %s\n", NULL_string);
	printf("\n");

	

	//my ft_printf 
	printf("My Ft_Printf:\n");
	printf("\n");

	ft_printf("= %i\n", number);
	ft_printf("= %i\n", cero_number);
	ft_printf("= %i\n", negative_number);
	ft_printf("= %i\n", min_number);
	ft_printf("= %d\n", max_number);
	ft_printf("= %u\n", unsigned_number);
	ft_printf("= %x\n", hexadecimal_number);
	ft_printf("= %x\n", negative_hexadecimal_number);
	ft_printf("= %X\n", hexadecimal_number);
	ft_printf("= %X\n", negative_hexadecimal_number);
	ft_printf("= %c\n", simple_char);
	ft_printf("= %c\n", especial_char);
	ft_printf("= %s\n", string);
	ft_printf("= %s\n", empty_string);
	ft_printf("= %p\n", pointer);
	ft_printf("%s\n", NULL_string);
	printf("\n\n");

	int	i;
	int j;
	i = ft_printf("Hola Mundo, 658 %p, %s, %s, %%, %c, %d, %i, %u, %x, %X,
		 %s\n",pointer, "", "hola", 'W', -30, 200,  0, 1565, 1565, NULL_string);
	j = printf("Hola Mundo, 658 %p, %s, %s, %%, %c, %d, %i, %u, %x, %X,
		 %s\n",pointer, "", "hola", 'W', -30, 200,  0, 1565, 1565, NULL_string);
	printf("%i = %i\n", i, j);
	ft_printf("%i = %i\n", i, j);

	return (0);
}
 */