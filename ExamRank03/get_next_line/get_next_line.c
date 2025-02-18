#include "get_next_line.h"
#include <stdlib.h>
#include <string.h>

static char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (strlen(s) + 1));
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

static void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d == s || len == 0)
		return (dst);
	if (d < s)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
	}
	return (dst);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	int			i_buff;
	int			i;
	int			j;
	static char	line[800000];
	static char	storage[800000];

	char buffer[BUFFER_SIZE + 1]; // malloqueado
	bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	i_buff = 0;
	j = 0;
	if (storage[0] != '\0')
	{
		while (storage[j] != '\n' && storage[j] != '\0')
		{
			line[i] = storage[j];
			i++;
			j++;
		}
		if (storage[j] == '\n')
		{
			line[i++] = storage[j++];
			line[i] = '\0';
			ft_memmove(storage, storage + j, 800000 - j);
			return (ft_strdup(line));
		}
		storage[0] = '\0';
	}
	while (1)
	{
		i_buff = 0;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		while (i_buff < bytes_read && buffer[i_buff] != '\n')
			line[i++] = buffer[i_buff++];
		if (i_buff < bytes_read && buffer[i_buff] == '\n')
		{
			line[i++] = buffer[i_buff++];
			line[i] = '\0';
			while (i_buff < bytes_read)
				storage[j++] = buffer[i_buff++];
			storage[j] = '\0';
			return (ft_strdup(line));
		}
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}

int	main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("test", O_RDONLY);
	line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
	close(fd);
	return (0);
}
