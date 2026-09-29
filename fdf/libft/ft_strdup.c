/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:07:31 by Vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/20 08:43:00 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	length;
	size_t	i;

	length = 0;
	while (str[length])
		length++;
	dest = (char *)malloc(length + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/* The strdup() function allocates sufficient memory for
a copy of the string s1, does the copy, and returns a
pointer to it. The pointer may subsequently be used
as an argument to the function	free(3).
If insufficient memory is available, NULL is returned
and errno is set to ENOMEM. */
/*
int	main(void)
{
	const char *original;
	char *duplicate;

	original = "Hello, world!";
	duplicate = ft_strdup(original);

	if (duplicate == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}

	printf("Original string: %s\n", original);
	printf("Duplicated string: %s\n", duplicate);

	free(duplicate); // Don't forget to free the memory allocated by ft_strdup

	return (0);
}  */