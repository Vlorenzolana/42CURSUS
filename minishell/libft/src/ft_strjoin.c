/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:25:45 by dalabrad          #+#    #+#             */
/*   Updated: 2025/03/21 17:04:55 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*rtrn;
	char	*tmp;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	rtrn = (char *)malloc(sizeof(char) * (len + 1));
	if (rtrn == NULL)
		return (NULL);
	rtrn = (char *)ft_memcpy(rtrn, s1, ft_strlen(s1));
	tmp = rtrn + ft_strlen(s1);
	tmp = (char *)ft_memcpy(tmp, s2, ft_strlen(s2));
	rtrn[len] = '\0';
	return (rtrn);
}
