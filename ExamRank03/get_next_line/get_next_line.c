#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 1000

typedef struct s_buff
{
	char	buffer[BUFFER_SIZE + 1];
	char	*cur;
}			t_buff;

char	*ft_strchr(char *s)
{
	while (*s && *s != '\n')
		++s;
	return (s);
}

int	ft_nlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		++i;
	if (s[i] == '\n')
		++i;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;

	ret = malloc((ft_nlen(s1) + ft_nlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	if (s1)
		while (*s1)
			ret[i++] = *(s1++);
	if (s2)
		while (*s2 && *s2 != '\n')
			ret[i++] = *(s2++);
	if ((s2 && *s2 == '\n') || (s1 && *s1 == '\n'))
		ret[i++] = '\n';
	ret[i] = 0;
	return (ret);
}

char	*get_next_line(int fd)
{
	static t_buff	buff;
	char			*index;
	char			*tmp;
	char			*line;

	if (BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (!buff.cur || !*buff.cur)
		{
			fd = read(fd, buff.buffer, BUFFER_SIZE);
			if (fd >= 0)
				buff.buffer[fd] = 0;
			buff.cur = buff.buffer;
			if (fd < 1)
				return (line);
		}
		index = ft_strchr(buff.cur);
		if (*index)
		{
			tmp = line;
			line = ft_strjoin(tmp, buff.cur);
			if (tmp)
				free(tmp);
			buff.cur = index + 1;
			return (line);
		}
		else
		{
			tmp = line;
			line = ft_strjoin(tmp, buff.cur);
			if (tmp)
				free(tmp);
			buff.cur = index;
		}
	}
	return (line);
}

/*--------------------------TEST--------------------------*/
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*new_line;

	fd = open("test", O_RDONLY);
	new_line = NULL;
	if (fd < 1)
		write(1, "\033[0;35m!!! FILE NOT OPENED !!!\n", 47);

	write(1, "\033[0;32m!!! GNL GO !!!\n", 23);
	while (1)
	{
		new_line = get_next_line(fd);
		printf("%s", new_line);
		if (new_line)
			free(new_line);
		else
			break ;
	}
	close(fd);
	return (0);
}
