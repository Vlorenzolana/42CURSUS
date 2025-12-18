/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaya-g <aamaya-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:34:42 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/12/17 16:58:04 by aamaya-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_lines(char *str)
{
	int	count;
	int	i;

	if (!str || !*str)
		return (0);
	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	*get_line_from_str(char *str, int *pos)
{
	int		start;
	int		len;
	char	*line;

	start = *pos;
	len = 0;
	while (str[*pos] && str[*pos] != '\n')
	{
		len++;
		(*pos)++;
	}
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, str + start, len);
	line[len] = '\0';
	if (str[*pos] == '\n')
		(*pos)++;
	return (line);
}

char	**split_preserving_empty(char *str)
{
	char	**out;
	int		line_count;
	int		pos;
	int		i;

	if (!str)
		return (NULL);
	line_count = count_lines(str);
	out = malloc(sizeof(char *) * (line_count + 1));
	if (!out)
		return (NULL);
	pos = 0;
	i = 0;
	while (i < line_count && str[pos])
	{
		out[i] = get_line_from_str(str, &pos);
		if (!out[i])
		{
			free_split(out);
			return (NULL);
		}
		i++;
	}
	out[i] = NULL;
	return (out);
}

static void	read_fd_into_accum(int fd, char **accum)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(*accum, line);
		free(*accum);
		free(line);
		if (!tmp)
			error_exit("Error: join failed");
		*accum = tmp;
		line = get_next_line(fd);
	}
	close(fd);
}

char	**read_file_to_array(char *path)
{
	int		fd;
	char	*accum;
	char	**out;

	fd = open_and_init(path, &accum);
	read_fd_into_accum(fd, &accum);
	if (!*accum)
	{
		free(accum);
		error_exit("Error: Empty .cub file");
	}
	out = split_preserving_empty(accum);
	free(accum);
	if (!out)
		error_exit("Error: split failed");
	return (out);
}
