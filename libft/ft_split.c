/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:25:51 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/05/15 09:38:05 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int word_count(const char *str, char c);
static char *fill_word(const char *str, int start, int end);
static void *ft_free(char **strs, int count);
/* you'll probably find another way to do this than what I did
 * it's not the best thing I did, but it works
 */
static void ft_initiate_vars(size_t *i, int *j, int *s_word);

char **ft_split(const char *s, char c)
{
    char **res;
    size_t i;
    int j;
    int s_word;
    
    ft_initiate_vars(&i, &j, &s_word);
    /* allocate a table big enough to hold all the words */
    res = ft_calloc((word_count(s, c) + 1), sizeof(char *));
    if (!res)
        return (NULL);
    /* loop over the whole string */
    while (i <= ft_strlen(s))
    {
        /* this check let's us find the index of the first
         * character of the word in the string.
         * s_word acts as a trigger so that we don't update
         * the index each time around the loop
         */
        if (s[i] != c && s_word < 0)
            s_word = i;
        /* if we found the start of a word and then another
         * separator, we know that we reached the end of the word
         * this could also be the end of the string
         */
        else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
        {
            /* j is the index of the word in our words array
             * so here we give the full string, the start index 
             * of the word, and the current i, which is the end
             * of the word to the fill_word function which will
             * return an allocated word and set it to res[j]
             */
            res[j] = fill_word(s, s_word, i);
            /* if fill_word failed to allocate memory
            * we have to free everything, so we call the ft_free
            * function with the words array and j which is the 
            * number of word we already saved
            */
            if (!(res[j]))
                return (ft_free(res, j));
            /* when we saved our word, we reset our s_word to -1
             * so it can trigger the next word when we go back
             * around the loop
             */
            s_word = -1;
            j++;
        }
        i++;
    }
    return (res);
}

/* please find another way to do this, please */
static void ft_initiate_vars(size_t *i, int *j, int *s_word)
{
    *i = 0;
    *j = 0;
    *s_word = -1;
}

static void *ft_free(char **strs, int count)
{
    /* in this loop
     * we loop over each element of the words array 
     * and we free it
     */
    int i;
    
    i = 0;
    while (i< count)
    {
        free(strs[i]);
        i++;
    }
    /* when we freed every element
     * we can free the words array
     */
    free(strs);
    return (NULL);
}

static char *fill_word(const char *str, int start, int end)
{
    char *word;
    int i;
    
    i = 0;
    /* allocating enough memory to store the word */
    word = malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);
    /* this loop copies the word from str to word
     */
    while (start < end)
    {
        word[i] = str[start];
        i++;
        start++;
    }
    /* we set the last character to 0 to NUL-terminate the string
     * and then we return the word
     * this word will be stored in our words array
     */
    word[i] = 0;
    return (word);
}

static int word_count(const char *str, char c)
{
    int count;
    int x;
    
    count = 0;
    x = 0;
    /* x is a trigger, we start counting the word only if it equals 0
     * this let's us skip all the separators, as while it is a separator
     * the x variable will still be 0
     * to make it clearer, we loop over the whole string, when we
     * encounter a character that is not a separator and our trigger is 0
     * we add one to our word count and set our trigger to 1 so it will
     * not count another word until we find another separator
     * when we found a separator, we set our trigger to 0 again so that
     * we can count another word if there's one
     * the trigger helps us take care of the strings that are only
     * composed of separator
     */
    while (*str)
    {
        if (*str != c && x == 0)
        {
            x = 1;
            count++;
        }
        else if (*str == c)
            x = 0;
        str++;
    }
    return (count);
}

#include "libft.h"
#include <stdio.h> // For printf and free

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <string> <delimiter>\n", argv[0]);
        return (1); // Indicate error
    }

    char **split_words = ft_split(argv[1], *argv[2]);

    if (!split_words) {
        printf("Error: Memory allocation failed.\n");
        return (1); // Indicate error
    }

    int i = 0;
    while (split_words[i]) {
        printf("%s\n", split_words[i]);
        i++;
    }

    // Free the memory allocated by ft_split
    ft_free(split_words, i); // Assuming ft_free handles NULL pointers

    return (0);
}