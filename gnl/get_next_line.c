/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 08:25:43 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/06/21 15:55:35 by vlorenzo         ###   ########.fr       */
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
	static char	*storage;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	bytes_read = 1;
	while (0 < bytes_read && !ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	if (bytes_read == -1)
		free(storage);
	if (!storage)
		return (NULL);
	to_print = ft_printcut(storage);
	storage = ft_trimcut(storage);
	return (to_print);
}

/* int	main(int argc, char **argv)
{
	int		fd;
	char	*test_str;

	if (argc != 2)
	{
		write(1, "Argument count must be exactly 2.\n", 35);
		return (1);
	}
	test_str = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write (1, "Could not open file\n", 21);
		return (1);
	}
	test_str = get_next_line(fd);
	while (test_str)
	{
		printf("Result: %s", test_str);
		free(test_str);
		test_str = get_next_line(fd);  // Update test_str inside the loop
	}
	close (fd);
	return (0);
} */
//For compiling
/* cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 get_next_line.c
get_next_line_utils.c && ./a.out file1.txt */