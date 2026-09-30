/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_envp_array_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 22:11:17 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/17 13:05:59 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

int	env_count(t_env *env)
{
	int	n;

	n = 0;
	while (env)
	{
		n++;
		env = env->next;
	}
	return (n);
}

char	*env_build_kv(t_env *e)
{
	char	*kv;
	char	*tmp;

	if (!e || !e->name)
		return (NULL);
	tmp = ft_strjoin(e->name, "=");
	if (!tmp)
		return (NULL);
	if (e->value)
		kv = ft_strjoin(tmp, e->value);
	else
		kv = ft_strjoin(tmp, "");
	free(tmp);
	return (kv);
}

void	free_envp_array(char **envp)
{
	int	i;

	if (!envp)
		return ;
	i = 0;
	while (envp[i])
		free(envp[i++]);
	free(envp);
}

char	**env_to_array(t_env *list)
{
	int		i;
	int		n;
	char	**arr;

	n = env_count(list);
	arr = (char **)ft_calloc(n + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (list)
	{
		arr[i] = env_build_kv(list);
		if (!arr[i])
			return (free_envp_array(arr), NULL);
		i++;
		list = list->next;
	}
	arr[i] = NULL;
	return (arr);
}
