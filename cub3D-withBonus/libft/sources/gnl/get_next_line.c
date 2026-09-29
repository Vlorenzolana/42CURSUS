/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:34:29 by aamaya-g          #+#    #+#             */
/*   Updated: 2025/07/23 14:53:00 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*left_over[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	fill_buffer(fd, buffer, &left_over[fd]);
	free(buffer);
	line = set_line(&left_over[fd]);
	if (!line)
	{
		free(left_over[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}

char	*copy_line(char *left_over)
{
	char	*line;
	int		i;

	i = 0;
	if (line_len(left_over) == 0 && !ft_strchr_gnl(left_over, '\n'))
		return (NULL);
	line = malloc((line_len(left_over) + 1) * sizeof(char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	while ((left_over)[i] != '\n' && (left_over)[i])
	{
		line[i] = (left_over)[i];
		i++;
	}
	line[i] = (left_over)[i];
	if ((left_over)[i] != '\0')
		line[i + 1] = '\0';
	return (line);
}

char	*set_line(char **left_over)
{
	char	*line;
	char	*temp;

	if (!*left_over)
		return (NULL);
	temp = *left_over;
	line = copy_line(*left_over);
	*left_over = ft_strdup_gnl(*left_over + line_len(*left_over));
	if (!**left_over)
	{
		free(*left_over);
		*left_over = NULL;
	}
	free(temp);
	return (line);
}

void	fill_buffer(int fd, char *buffer, char **left_over)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return ;
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = *left_over;
		*left_over = ft_strjoin_special(temp, buffer, bytes_read);
		free(temp);
		temp = NULL;
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
}

/* int	main(void)
{
	int		fd, fd1, fd2;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	if (fd == -1 || fd1 == -1 || fd2 == -1)
		return (perror("open"), 1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf ("%s", line);
		free(line);
	}
	printf("\n");
	while (1)
	{
		line = get_next_line(fd1);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	printf("\n");
	while (1)
	{
		line = get_next_line(fd2);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	close(fd1);
	close(fd2);
	return (0);
}  */