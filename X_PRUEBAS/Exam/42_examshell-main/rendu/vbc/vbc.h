#ifndef VBC_H
# define VBC_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int unexpected(char c);
int ft_sum(void);
int ft_mul(void);
int ft_factor(void);
int check_input(char *str);

#endif