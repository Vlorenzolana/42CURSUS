#ifndef GNL_H
# define GNL_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 21
# endif

char	*get_next_line(int fd);

#endif