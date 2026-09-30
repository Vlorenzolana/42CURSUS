/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_envp_array_resync.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:51:54 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/17 13:03:23 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

void	ft_free_split(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static size_t	count_visible_envs(t_env *env)
{
	size_t	count;

	count = 0;
	while (env)
	{
		if (env->visible)
			count++;
		env = env->next;
	}
	return (count);
}

static char	*join_env_var(t_env *var)
{
	char	*joined;
	size_t	len;

	if (!var || !var->name || !var->value)
		return (NULL);
	len = ft_strlen(var->name) + ft_strlen(var->value) + 2;
	joined = malloc(len);
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, var->name, len);
	ft_strlcat(joined, "=", len);
	ft_strlcat(joined, var->value, len);
	return (joined);
}

int	rebuild_array_visible(char ***dst_envp, t_env *env_list)
{
	size_t	count;
	size_t	i;
	t_env	*env;

	if (!dst_envp)
		return (1);
	ft_free_split(*dst_envp);
	*dst_envp = NULL;
	count = count_visible_envs(env_list);
	*dst_envp = malloc(sizeof(char *) * (count + 1));
	if (!*dst_envp)
		return (1);
	env = env_list;
	i = 0;
	while (env)
	{
		if (env->visible)
		{
			(*dst_envp)[i] = join_env_var(env);
			if (!(*dst_envp)[i++])
				return (1);
		}
		env = env->next;
	}
	return ((*dst_envp)[i] = NULL, 0);
}

int	resync_env_array(char ***dst_envp, t_env *list)
{
	char	**fresh;

	if (!dst_envp)
		return (1);
	fresh = env_to_array(list);
	if (!fresh)
		return (1);
	free_envp_array(*dst_envp);
	*dst_envp = fresh;
	return (0);
}
