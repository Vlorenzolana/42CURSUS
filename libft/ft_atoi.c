/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vlorenzo <vlorenzo@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:05:52 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/04/20 12:12:58 by Vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

/*
NOTA: este codigo funciona tambien con str[i] == *str

atoi(const char *str);
#include <xlocale.h>
The atoi() function converts the initial 
portion of the string pointed to by str to
int representation. */
/* 
#include <stdio.h>
int main(void)
{
	int res1;
	int res2;
	int res3;
	int res4;
	int res5;

	char num1[] = {"1234567890"};
	char num2[] = {"-1234567890"};
	char num3[] = {"--1234567890"};
	char num4[] = {"---1234567890"};
	char num5[] = {"+1234567890"};

	res1 = ft_atoi(num1);
	printf("test 1 %d\n", res1);

	res2 = ft_atoi(num2);
	printf("test 2 %d\n", res2);

	res3 = ft_atoi(num3);
	printf("test 3 %d\n", res3);

	res4 = ft_atoi(num4);
	printf("test 4 %d\n", res4);

	res5 = ft_atoi(num5);
	printf("test 5 %d\n", res5);

	return(0);
}
 */