/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_envp_attribute_getters.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:41:33 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/08 23:41:36 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_exec.h"
#include "minishell_parsing.h"

/*
 * This function returns the string of the name of the given envp. Allocates the
 * memory for it, so it needs to be freed in case you want to destroy a node
 * of shell envp list.
 */
// Devuelve strdup de la parte izquierda de "VAR=valor"
char	*get_envp_name(char *envp_str)
{
	size_t	len;
	char	*equal;
	char	*name;

	if (!envp_str)
		return (NULL);
	equal = ft_strchr(envp_str, '=');
	if (!equal)
		return (NULL);
	len = equal - envp_str;
	name = (char *)malloc(len + 1);
	if (!name)
		return (NULL);
	ft_strlcpy(name, envp_str, len + 1);
	return (name);
}

/*
 * This function returns the string of the value of the given envp. Allocates
 * the memory for it, so it needs to be freed in case you want to destroy a
 * node of shell envp list.
 */
char	*get_envp_value(char *envp_str)
{
	char	*equals;

	equals = ft_strchr(envp_str, '=');
	if (!equals)
		return (ft_strdup(""));
	return (ft_strdup(equals + 1));
}

/*
 * This function checks in the envp list of minishell for name parameter
 * and returns the value string if exists. If parameter dosen`t exist or malloc
 * error occurs NULL is returned.
 */
char	*get_shell_envp_value(t_env *shell_envp, const char *name)
{
	char	*value;

	if (!shell_envp || !name)
		return (NULL);
	value = NULL;
	while (shell_envp)
	{
		if (!strncmp(shell_envp->name, name, strlen(name))
			&& !strncmp(shell_envp->name, name, strlen(shell_envp->name)))
		{
			value = ft_strdup(shell_envp->value);
			if (!value)
			{
				error_msg(MALLOC_ERROR);
				return (NULL);
			}
			return (value);
		}
		shell_envp = shell_envp->next;
	}
	return (NULL);
}

char	*get_shell_envp_str(t_env *shell_envp)
{
	char	*str;
	size_t	name_len;
	size_t	value_len;
	size_t	total_len;

	if (!shell_envp)
		return (NULL);
	name_len = ft_strlen(shell_envp->name);
	value_len = ft_strlen(shell_envp->value);
	total_len = name_len + value_len + 2;
	str = (char *)malloc(sizeof(char) * total_len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, shell_envp->name, total_len);
	ft_strlcat(str, "=", total_len);
	if (shell_envp->value)
		ft_strlcat(str, shell_envp->value, total_len);
	return (str);
}
