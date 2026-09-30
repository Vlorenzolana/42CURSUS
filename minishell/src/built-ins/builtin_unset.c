/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:54:49 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/15 17:49:20 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

static int	is_valid_name(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	env_unset_one(t_env **env, const char *name)
{
	t_env	*cur;
	t_env	*prev;

	if (!env || !*env || !name)
		return (0);
	cur = *env;
	prev = NULL;
	while (cur)
	{
		if (!ft_strcmp(cur->name, name))
		{
			if (prev)
				prev->next = cur->next;
			else
				*env = cur->next;
			free(cur->name);
			free(cur->value);
			free(cur);
			return (1);
		}
		prev = cur;
		cur = cur->next;
	}
	return (0);
}

int	shell_unset(char **args, t_data *data)
{
	int	i;
	int	changed;

	if (!args || !args[0])
		return (EXIT_SUCCESS);
	i = 0;
	changed = 0;
	while (args[i])
	{
		if (is_valid_name(args[i]) && env_unset_one(&(data->shell_envp),
				args[i]))
			changed = 1;
		i++;
	}
	if (changed && resync_env_array(&(data->envp_exec), data->shell_envp))
		return (1);
	return (EXIT_SUCCESS);
}
