/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:45:40 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/30 10:38:35 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str(char **argv)
{
	int	i;

	if (!argv || !*argv)
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	argv = NULL;
}

void	free_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if ((argc < 2) || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = tidy_arg(argv[1]);
	create_stack(&a, argv, argc == 2);
	if (argc == 2)
		free_str(argv);
	if (!sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
	return (0);
}

/*
For CHECKER_LINUX in your terminal you can run the command:
% ARG="[ARGUMENTS]"; ./push_swap $ARG | tee >(wc -l) | ./checker_linux $ARG

VERIFY PERMISSIONS:
You can verify the -x permissions by running the following command:
% ls -l checker_linux
% If not -x permissions you can run:
chmod 777 checker_linux


Re-run your original command:
% ./push_swap $ARG | tee >(wc -l) | ./checker_linux $ARG
*/

/* TEST EVALUATION:
//with ""
./push_swap "9 99 88 8 77 7 66 6 55 5 44 4 33 3 22 2 11 1
9999 8888 7777 6666 5555 4444 3333 2222 1111 999 888 777
666 555 444 333 222 111 99999 88888 77777 66666 55555 44444
33333 22222 11111 999999 888888 777777 666666 555555 444444
333333 222222 111111"

//without ""
./push_swap 9 99 88 8 77 7 66 6 55 5 44 4 33 3 22 2 11 1
9999 8888 7777 6666 5555 4444 3333 2222 1111 999 888 777
666 555 444 333 222 111 99999 88888 77777 66666 55555 44444
33333 22222 11111 999999 888888 777777 666666 555555 444444
333333 222222 111111

//100 num
./push_swap "123 456 789 10 234 567 890 12 345 678 901 23 45 67 89 101
234 567 890 123 45 67 8 901 234 56 789 10 234 56 78 901 234
567 89 101 234 567 890 123 456 789 10 234 567 890 12 345 678
901 23 45 67 89 101 234 567 890 123 45 67 8 901 234 56 789 10
234 56 78 901 234 567 89 101 234 567 890 123 456 789 10 234 567
33333 22222 11111 999999 888888 777777 666666 555555 444444
234 56 789 10 234 56 78 901 234 567 89 101 234 567 890 123 456
789 10 234 567 890 12 345 678 901 23 45 67 89 101 234 567 890 123
45 67 8 901 234 56 789 10 234 56 78 901 234 567 89 101 234 567 890"
*/

/*
//Random num 500 MAX
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 500

int	random_int(void)
{
	int	high;
	int	low;

	high = rand();
	low = rand();
	return ((high << 16) | (low & 0xFFFF));
		// Combina para obtener un entero completo
}

int	main(void)
{
	int	numbers[MAX_NUMBERS];
	int	j;

	int i, temp;
	srand(time(NULL));
	i = 0;
	while (i < MAX_NUMBERS)
	{ // Marcamos posiciones vacías con INT_MAX
		i++;
	}
	i = 0;
	while (i < MAX_NUMBERS)
	{
		// Generamos un número aleatorio entre INT_MIN y INT_MAX
		temp = random_int();
		// Comprobamos si el número ya está en el array
		j = 0;
		while (j < i)
		{
			if (numbers[j] == temp)
			{
				break ;
			}
			j++;
		}
		// Si el número no está repetido, lo añadimos al array
		if (j == i)
		{
			numbers[i] = temp;
			i++;
		}
	}
	// Imprimimos el array de números generados
	i = 0;
	printf("\"");
	while (i < MAX_NUMBERS) {
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\"\n");
	return (0);
}
*/

/*
valgrind ./push_swap ""
Error
Invalid single argument, non-digit found
valgrind ./push_swap "42"
Debug: All arguments processed successfully.
valgrind ./push_swap "+42"
Debug: All arguments processed successfully.
valgrind ./push_swap "-42"
Debug: All arguments processed successfully.
valgrind ./push_swap "34 45 6"
Debug: All arguments processed successfully.
valgrind ./push_swap " 34 45 6 "
Debug: All arguments processed successfully.
valgrind ./push_swap "0045"     
Debug: All arguments processed successfully.
valgrind ./push_swap "000000000000000000000045"
Debug: All arguments processed successfully.
valgrind ./push_swap "-000000000000000000000045"
Debug: All arguments processed successfully.
valgrind ./push_swap "+000000000000000000000045"
Debug: All arguments processed successfully.
valgrind ./push_swap "-42 +56 78"               
Debug: All arguments processed successfully.
valgrind ./push_swap "1234567890"
Debug: All arguments processed successfully.
valgrind ./push_swap  "123456789012"
Error
Invalid single argument, non-digit found
valgrind ./push_swap "42a56"        
Error
Invalid single argument, non-digit found
valgrind ./push_swap "--42" 
Error
Invalid single argument, non-digit found
valgrind ./push_swap "++42"
Error
Invalid single argument, non-digit found
valgrind ./push_swap "+-42"
Error
Invalid single argument, non-digit found
valgrind ./push_swap " "   
Error
Invalid single argument, non-digit found
valgrind ./push_swap "           "
Error
Invalid single argument, non-digit found
valgrind ./push_swap  "012 12"    
Error
Duplicate number found
valgrind ./push_swap  "12 12" 
Error
Duplicate number found
valgrind ./push_swap 42 56 78
Debug: All arguments processed successfully.
valgrind ./push_swap -42 -56 -78
Debug: All arguments processed successfully.
valgrind ./push_swap  42 -56 78
Debug: All arguments processed successfully.
valgrind./push_swap 00042 0056 00078
Debug: All arguments processed successfully.
valgrind ./push_swap 42 abc -56
Error
Invalid multiple arguments, non-digit found
valgrind ./push_swap 42 56 42
Error
Duplicate number found
valgrind ./push_swap 2147483648 -2147483649
Error
Under- and over- flow int found
valgrind ./push_swap 2147483647 -2147483648
Debug: All arguments processed successfully.
valgrind ./push_swap 42 56
Debug: All arguments processed successfully.
valgrind ./push_swap 4 2 5 6 7 8
Debug: All arguments processed successfully.
valgrind ./push_swap 42 - 56 + 78
Error
Invalid multiple arguments, non-digit found
valgrind ./push_swap 012 12
Error
Duplicate number found
valgrind./push_swap 12 12 
Error
Duplicate number found
valgrind ./push_swap -0   
Debug: All arguments processed successfully.
valgrind./push_swap 000000000000 00000000000000
Error
Duplicate number found
valgrind ./push_swap "000000000000 00000000000000"
Error
Duplicate number found
valgrind ./push_swap "+9999999999999999"          
Error
Invalid single argument, non-digit found
 valgrind./push_swap +9999999999999999 
Error
Invalid single argument, non-digit found
valgrind ./push_swap -9999999999999999 
Error
Invalid single argument, non-digit found
valgrind ./push_swap "-9999999999999999"
Error
Invalid single argument, non-digit found
valgrind ./push_swap  "0 0 0"
Error
Duplicate number found
valgrind ./push_swap 0 0 0   
Error
Duplicate number found
valgrind ./push_swap "2147483647 2147483646 -2147483647"
Debug: All arguments processed successfully.
valgrind ./push_swap "9223372036854775807"
Error
Invalid single argument, non-digit found
valgrind ./push_swap 9223372036854775807 
Error
Invalid single argument, non-digit found
valgrind ./push_swap -9223372036854775807
Error
Invalid single argument, non-digit found
valgrind ./push_swap +9223372036854775807
Error
Invalid single argument, non-digit found
valgrind./push_swap "-9223372036854775807"
Error
Invalid single argument, non-digit found
valgrind ./push_swap "+9223372036854775807"
Error
Invalid single argument, non-digit found
valgrind ./push_swap '42 56 78'
Debug: All arguments processed successfully.
valgrind  ./push_swap '012 12'  
Error
Duplicate number found
valgrind ./push_swap 42 56 abc 78
Error
Invalid multiple arguments, non-digit found
valgrind ./push_swap """"        
Error
Invalid single argument, non-digit found
valgrind ./push_swap "" ""
Error
Invalid multiple arguments, non-digit found
valgrind ./push_swap NULL 
Error
Invalid single argument, non-digit found
valgrind./push_swap "a-42"
Error
Invalid single argument, non-digit found
valgrind ./push_swap "2147483647 0 -2147483648"
Debug: All arguments processed successfully.
valgrind ./push_swap "2147483647 -2147483648"
Debug: All arguments processed successfully.
valgrind ./push_swap "2147483647 -21474836490"
Error
Under- and over- flow int found
valgrind ./push_swap "2147483647 -2147483649" 
Error
Under- and over- flow int found
valgrind ./push_swap "2147483647 -214748364" 
Debug: All arguments processed successfully.
valgrind ./push_swap "2147483647 -2147483648"
Debug: All arguments processed successfully.*/