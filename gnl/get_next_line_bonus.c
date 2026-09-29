/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:25:43 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/29 11:30:57 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trimcut(char *storage)
{
	char	*new_storage;
	size_t	i;
	size_t	j;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free (storage);
		return (NULL);
	}
	new_storage = ft_calloc((ft_strlen(storage) - i + 1), sizeof(char));
	if (!new_storage)
		return (NULL);
	i = i + 1;
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	new_storage[j] = '\0';
	free (storage);
	return (new_storage);
}

char	*ft_printcut(char *storage)
{
	char	*to_print;
	size_t	i;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	to_print = ft_calloc((i + 2), sizeof(char));
	if (!to_print)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		to_print[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		to_print[i] = storage[i];
		i++;
	}
	to_print[i] = '\0';
	return (to_print);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*to_print;
	int			bytes_read;
	static char	*storage[4096];

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	bytes_read = 1;
	while (0 < bytes_read && !ft_strchr(storage[fd], '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		storage[fd] = ft_strjoin(storage[fd], buffer);
	}
	if (bytes_read == -1)
		free(storage[fd]);
	if (!storage[fd])
		return (NULL);
	to_print = ft_printcut(storage[fd]);
	storage[fd] = ft_trimcut(storage[fd]);
	return (to_print);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	int		fd3;
	char *	str;

	if (argc != 4)
	{
		write(1, "Argument count must be exactly 2.\n", 35);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);

	//Open diff files randomly: text1.txt text2.txt text3.txt
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd3);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd2);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd2);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd3);
	printf("%s", str);
	free(str);
	
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	
	close (fd);
	close (fd2);
	close (fd3);
	return (0);
}
//For compiling
/* cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c
get_next_line_utils.c && ./a.out file1.txt */