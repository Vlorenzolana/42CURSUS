/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_expands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:59:35 by vlorenzo          #+#    #+#             */
/*   Updated: 2025/09/23 18:57:46 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_utils.h"
#include "minishell_exec.h"
#include "minishell_parsing.h"

int extern	g_status;

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
	{
		free(s1);
		return (ft_strdup(""));
	}
	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

char	*ft_strjoin_char_free(char *s1, char c)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	return (ft_strjoin_free(s1, str));
}

char	*get_env_value_from_list(const char *name, t_env *env)
{
	while (env)
	{
		if (ft_strcmp(env->name, name) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

int	handle_exit_status(char **result, int g_status)
{
	char	*exit_code;

	exit_code = ft_itoa(g_status);
	if (!exit_code)
		return (1);
	*result = ft_strjoin_free(*result, exit_code);
	free(exit_code);
	return (0);
}

size_t	handle_variable(const char *str, size_t i, char **result, t_env *env)
{
	size_t	start;
	char	*var;
	char	*value;

	start = i;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	var = ft_substr(str, start, i - start);
	value = get_env_value_from_list(var, env);
	if (!value)
		value = "";
	*result = ft_strjoin_free(*result, value);
	free(var);
	return (i);
}
