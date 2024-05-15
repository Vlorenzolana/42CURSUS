/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:38:45 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/15 12:49:20 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int int_len(long nbr);
static char *pre_conv(int len);

char *ft_itoa(int n)
{
    int len;
    int i;
    char *result;
    long nbr;
    
    /* here I convert the int n received as parameter to a long
     * this is only done so that INT_MIN and INT_MAX are not a problem
     * and I can treat them the exact same way as all other numbers
     */
    nbr = n;
    /* getting the length of the number */
    len = int_len(nbr);
    /* allocating the string with the correct size and 
     * settings result[0] = '0'
     */
    result = pre_conv(len);
    if (!result)
        return (NULL);
    /* if the number is less than 0, we do the same thing as in the
     * int_len function, we set the number equals to minus itselft. 
    if (nbr < 0)
        nbr = -nbr;
    /* we then set i = len - 1, len take into account the NUL-terminating
     * character and we don't want to overwrite ti.
    i = len - 1;
     /* then we can make the conversion from int to character */
    while (nbr != 0)
    {
        result[i] = ((nbr % 10) + 48);
        nbr = nbr / 10;
        i--;
    }
    /* if the original number was negative, we set the first character equals to null/ 0;8/
    if (n < 0)
        result[0] = '-';
    result[len] = 0;
    /* At the very end, we can return the string we just craeated \*
    return (result);
}

static char *pre_conv(int len)
{
    char *tmp;
    
    /* we allocate enough memory for len + 1 character so we
     * don't skip the NUL-terminating character
     */
    tmp = malloc((len + 1) * sizeof(char));
    if (!tmp)
        return (NULL);
    /* here I set the index 0 of the newly allocated string to be 
     * character 0.
     * I do this here, because in the ft_itoa function, if the number
     * is 0, it will result in no condition working, and if I don't
     * set the first character working, we would have whatever value
     * was in memory at tmp[0], maybe the character 0, but most often
     * this will be some random junk value
     */
    tmp[0] = '0';
    return (tmp);
}

static int_len(long nbr)
{
    int count;
    
    count = 0;
    /* the number is less than 0, we add one to the count to take
     * into account the - we'll have to add at the end
     * and we set the number equal to minus itself so it becomes 
     * positive
     */
    if (nbr < 0)
    {
        count++;
        nbr = -nbr;
    }
    /* if the number equals 0, we have to add 1 to the count
     * you could skip this check by starting the count variable at 1
     * instead of 0
     */
    if (nbr == 0)
        count++;
    /* if we get to this point, the number will be different than 0
     * we then divide the number by ten and add 1 to the count each
     * time through the loop
     */
    while (nbr != 0)
    {
        nbr /= 10;
        count++;
    }
    /* we can finally return the count that is how much characters are
     * needed to represent this number as string
     */
    return (count);
}
/* 
#include "libft.h"
#include <stdio.h> // For printf and free

int main(void) {
    int num_to_convert = -12345;
    char *str_rep;

    str_rep = ft_itoa(num_to_convert);

    if (!str_rep) {
        printf("Error: Memory allocation failed.\n");
        return (1); // Indicate error
    }

    printf("Integer %d converted to string: %s\n", num_to_convert, str_rep);

    free(str_rep); // Important: Free the memory allocated by ft_itoa

    return (0);
} */