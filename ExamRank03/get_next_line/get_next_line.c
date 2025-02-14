#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*dup;

	i = 0;
	while (s[i])
		i++;
	dup = malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_i = 0;
	int			i;
	char		line[70000];

	static int buffer_readed = 0; // es un int no un char
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	while (1)
	{
		if (buffer_i >= buffer_readed)
		{
			buffer_readed = read(fd, buffer, BUFFER_SIZE);
			buffer_i = 0;
			if (buffer_readed <= 0) // Acordarse de esto
				break ;
		}
		line[i++] = buffer[buffer_i++];
		if (line[i - 1] == '\n' || line[i - 1] == EOF)
			break ;
	}
	if (i == 0) // acordarse que es i
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (printf("Fd cant be openned\n"), 1);

	while ((line = get_next_line(fd))) // acordarme que son 3 parentesis
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}