/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:29:51 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/26 17:34:15 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_utils.h"
#include "minishell_exec.h"
#include "minishell_parsing.h"

void	restore_stdio(int in_bk, int out_bk)
{
	if (in_bk >= 0)
		dup2(in_bk, STDIN_FILENO);
	if (out_bk >= 0)
		dup2(out_bk, STDOUT_FILENO);
	if (in_bk >= 0)
		close(in_bk);
	if (out_bk >= 0)
		close(out_bk);
}

void	reset_cmd_state(t_data *data)
{
	free_cmd_list(data->first_cmd);
	data->first_cmd = NULL;
}

void	process_input_line(char *line, t_data *data, int in, int out)
{
	char			**pipe_seg;
	t_tokens		**tokens;
	size_t			n_pipe;
	t_cleanup_args	args;

	if (!line || !*line)
		return ;
	n_pipe = 0;
	add_history(line);
	if (!ft_strcmp(line, "history"))
		return (print_history(), (void)0);
	if (!init_pipe_segments(line, &pipe_seg, &n_pipe))
		return ;
	tokens = init_tokens_by_segment(n_pipe);
	if (!tokens)
		return ;
	process_segments(pipe_seg, tokens, n_pipe, data);
	args.segments = pipe_seg;
	args.tokens = tokens;
	args.count = n_pipe;
	cleanup(args.segments, args.tokens, args.count);
	execute_pipeline(data);
	restore_stdio(in, out);
	reset_cmd_state(data);
}

void	close_in_out(int in, int out)
{
	if (in >= 0)
		close(in);
	if (out >= 0)
		close(out);
}

void	main_loop(t_data *data)
{
	char	*line;

	data->in = dup(STDIN_FILENO);
	data->out = dup(STDOUT_FILENO);
	if (data->in < 0 || data->out < 0)
		return (perror("dup"), (void)0);
	read_history(".minishell_history");
	while (1)
	{
		setup_signal_handlers();
		line = readline(PROMPT);
		if (!line)
			shell_exit(&line, data);
		process_input_line(line, data, data->in, data->out);
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	write_history(".minishell_history");
	rl_clear_history();
	close_in_out(data->in, data->out);
}
