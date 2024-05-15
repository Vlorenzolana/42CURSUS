/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:18:29 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/15 09:20:03 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(const char *s1, const char *s2)
{
    char *res;
    int i;
    int j;
    
    i = 0;
    j = 0;
    
    res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (!res)
        return (NULL);
   
    while (s1[i])
        res[j++] = s1[i++];
   
    i = 0;
    while (s2[i])
        res[j++] = s2[i];

    res[j] = 0;

    return (res);
}

#include "libft.h"
#include <stdio.h> // For printf

int main(void) {
    const char *string1 = "This is ";
    const char *string2 = "a string.";
    char *joined_string;

    joined_string = ft_strjoin(string1, string2);

    if (joined_string) {
        printf("Joined string: %s\n", joined_string);
        free(joined_string); // Important: Free the memory allocated by ft_strjoin
    } else {
        printf("Error: Memory allocation failed.\n");
    }

    return 0;
}