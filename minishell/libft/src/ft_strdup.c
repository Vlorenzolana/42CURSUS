/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:46:28 by dalabrad          #+#    #+#             */
/*   Updated: 2025/03/06 12:16:20 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (ptr == NULL)
		return (NULL);
	ptr = (char *)ft_memcpy(ptr, str, ft_strlen(str) + 1);
	return (ptr);
}
