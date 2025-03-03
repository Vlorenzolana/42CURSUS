#include <pthread.h>
#include <stdio.h>  // printf
#include <stdlib.h> //malloc
#include <unistd.h>

void	exit_on_error(int *num, int exit_code)
{
	free(num);
	exit(exit_code);
}

void	*routine_2(void *arg)
{
	int	*num;
	int	i;

	num = (int *)arg;
	i = 0;
	while (i < 100000)
	{
		(*num)++;
		i++;
	}
	return (NULL);
}

void	example_3(void)
{
	int			*num;
	pthread_t	t1;
	pthread_t	t2;

	num = malloc(sizeof(int));
	if (num == NULL)
		exit(1);
	*num = 0;
	if (pthread_create(&t1, NULL, routine_2, num))//init t1&return diff from 0 when creating error
		exit_on_error(num, 2);
	if (pthread_create(&t2, NULL, routine_2, num))
		exit_on_error(num, 2);
	if (pthread_join(t1, NULL))
		exit_on_error(num, 3);
	if (pthread_join(t2, NULL))
		exit_on_error(num, 3);
	printf("Num: %d\n", *num);
	/*
	pthread_join() returns 0 on success and a non-zero error code on failure.
	If	pthread_join(void) fails, the program calls exit_on_error(num, 3);.
	The number 3 is used as an error code to indicate that the program failed 
	when waiting for a thread to finish.
	*/
}

void	*print_hello(void *arg)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		printf("Hello\n");
		i++;
		usleep(100);
	}
	return (NULL);
}

void	*print_world(void *arg)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		printf("\t\tWorld\n");
		i++;
		usleep(100);
	}
	return (NULL);
}

void	example_2(void)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, print_hello, NULL))
		exit(1);
	if (pthread_create(&t2, NULL, print_world, NULL))
		exit(1);
	if (pthread_join(t1, NULL))
		exit(1);
	if (pthread_join(t2, NULL))
		exit(1);
}

/* void	example_1(void)
{
	print_hello(NULL);
	print_world(NULL);
} */

int	main(void)
{
	example_2();
	return (0);
}
