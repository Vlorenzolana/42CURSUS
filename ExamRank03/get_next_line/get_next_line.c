#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	while (str[i])
		i++;
	dup = malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_index;
	static int	buffer_readed;
	char		line[70000];
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_index >= buffer_readed)
		{
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_index = 0;
			if (buffer_readed <= 0)
				break ;
		}
		line[i++] = buffer[buffer_index++];
		if (line[i - 1] == '\n') // añadir EOF?
			break ;
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int	main(void)
{
	int fd;
	char *line;
	fd = open("text.txt", O_RDONLY);
	/*
	if (fd < 0)
			return (printf("cant open\n"), 1);
	//	This we shouldn't test here as we hand only the gnl function
	*/
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}