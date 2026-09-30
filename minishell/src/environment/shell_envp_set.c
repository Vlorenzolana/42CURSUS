/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_envp_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:42:02 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/17 13:13:58 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

/* Busca nombre exacto en la lista */
static t_env	*env_find(t_env *env, const char *name)
{
	while (env)
	{
		if (!ft_strcmp(env->name, name))
			return (env);
		env = env->next;
	}
	return (NULL);
}

/* Crea un nodo nombre/valor (valor "" si es NULL) */
static t_env	*env_new_pair(const char *name, const char *value)
{
	t_env	*e;

	e = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!e)
		return (NULL);
	e->name = ft_strdup(name);
	if (value)
		e->value = ft_strdup(value);
	else
		e->value = ft_strdup("");
	if (!e->name || !e->value)
	{
		free(e->name);
		free(e->value);
		free(e);
		return (NULL);
	}
	return (e);
}

void	replace_node_value(t_env *node, const char *value)
{
	free(node->value);
	if (value)
		node->value = ft_strdup(value);
	else
		node->value = ft_strdup("");
}

/* Upsert: si existe -> actualiza; si no -> crea y añade al final */
int	env_set(t_env **env, const char *name, const char *value)
{
	t_env	*node;
	t_env	*cur;

	if (!env || !name || !*name)
		return (1);
	node = env_find(*env, name);
	if (node)
	{
		replace_node_value(node, value);
		return (node->value == NULL);
	}
	node = env_new_pair(name, value);
	if (!node)
		return (1);
	if (!*env)
		*env = node;
	else
	{
		cur = *env;
		while (cur->next)
			cur = cur->next;
		cur->next = node;
	}
	return (0);
}
