#include "philo.h"

int	main(void)
{
	char	*str;
	int		fd;
	FILE	*t;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	// str = malloc(sizeof(char *));
	str = calloc(sizeof(char *), 50001);
	printf("%p\n", str);
	read(fd, str, 50000);
	printf("%s\n", str);
	printf("%p\n", str);
	t = fopen("test.txt", "r+");
	while (i++ < 50000)
		fprintf(t, "a");
	str = "hola qe ase";
	printf("%p\n", str);
	// printf("%s\n", str);
	// printf("%s\n", str);
	free(str);
	close(fd);
	fclose(t);
	return (0);
}
