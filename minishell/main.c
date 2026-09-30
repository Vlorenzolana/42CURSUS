/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:42:59 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/23 18:41:22 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "banner.h"
#include "minishell_exec.h"
#include "minishell_parsing.h"
#include "minishell_signals.h"

/* AUX TOKENS */
t_tokens	*get_tokens(void)
{
	static t_tokens	tokens;

	return (&tokens);
}

//////////////////////////////////
//------------MAIN---------------
//////////////////////////////////
int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	(void)argv;
	if (argc != 1)
	{
		printf("Too many arguments.\n");
		return (EXIT_FAILURE);
	}
	if (data_init(&data, envp))
	{
		printf("Failed to initialize data\n");
		return (EXIT_FAILURE);
	}
	print_mini42_banner();
	print_shell_banner();
	ft_putstr((char *)"\n");
	main_loop(&data);
	free_data(&data);
	return (EXIT_SUCCESS);
}
//////////////////////////////////
//----------END MAIN-------------
//////////////////////////////////