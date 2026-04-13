#ifndef VBC5_H
# define VBC5_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void unexpected(char c);
int ft_factor(void);
int ft_mult(void);
int ft_sum(void);
int check_input(char *str);

#endif