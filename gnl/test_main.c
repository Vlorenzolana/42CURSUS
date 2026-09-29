#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text1.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	printf("=== text1.txt ===\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);

	fd = open("text2.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	printf("=== text2.txt ===\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);

	fd = open("text3.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	printf("=== text3.txt ===\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
