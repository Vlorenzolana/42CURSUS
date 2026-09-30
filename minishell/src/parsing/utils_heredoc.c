/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 19:45:33 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/26 16:58:06 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

extern int	g_status;

static int	hd_is_delim(const char *line, const char *delim)
{
	size_t	len;

	if (!line || !delim)
		return (0);
	len = ft_strlen(line);
	if (len && line[len - 1] == '\n')
		len--;
	if (ft_strncmp(line, delim, len) == 0 && delim[len] == '\0')
		return (1);
	return (0);
}

static int	hd_write_line(int fd, const char *s)
{
	ssize_t	w;
	size_t	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	w = write(fd, s, len);
	if (w < 0 || (size_t)w != len)
		return (-1);
	return (0);
}

static int	hd_process_line(int fd, char **line, int quoted, t_env *env)
{
	char	*tmp;

	if (!quoted)
	{
		if (hd_expand_line(line, env) < 0)
			return (-1);
	}
	tmp = hd_add_nl(*line);
	if (!tmp)
		return (-1);
	free(*line);
	*line = tmp;
	if (hd_write_line(fd, *line) < 0)
		return (-1);
	return (0);
}

int	heredoc_loop(int fd, const char *delim, int quoted, t_env *env)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			heredoc_eof_warning(delim);
			break ;
		}
		if (hd_is_delim(line, delim))
		{
			free(line);
			return (0);
		}
		if (hd_process_line(fd, &line, quoted, env) < 0)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	return (0);
}

int	heredoc_loop_open(const char *delim, int quoted, t_env *env)
{
	int	fd;

	fd = open("/tmp/minishell_heredoc", O_CREAT | 01 | O_TRUNC, 0000644);
	if (fd < 0)
		return (-1);
	if (heredoc_loop(fd, delim, quoted, env) < 0)
	{
		close(fd);
		return (-1);
	}
	if (close(fd) < 0)
		return (-1);
	return (0);
}
