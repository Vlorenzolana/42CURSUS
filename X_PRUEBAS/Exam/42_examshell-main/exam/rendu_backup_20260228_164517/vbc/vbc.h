#ifndef VBC_H
#define VBC_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


void unexpected(char c);
int ft_factor();
int ft_product();
int ft_sum();
int check_input(char *str);

#endif
