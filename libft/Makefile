# **************************************************************************** #
# VARIABLES                                                                    #
# NAME: Define el nombre de la biblioteca que se creará (libft.a).             #
NAME = libft.a
# CC: Especifica el compilador a usar (gcc).                                   #
CC = gcc
# CCFLAGS: Define las opciones del compilador (-Wall -Wextra -Werror).         #
CCFLAGS = -Wall -Wextra -Werror
# RM: Comando para eliminar archivos (rm -rf).                                 #
RM = rm -rf
# SRCS: Lista los archivos fuente (.c) que forman parte de la biblioteca.      #
SRCS = 	ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_strchr.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strrchr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_putchar_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_putstr_fd.c\
	ft_substr.c\
	ft_split.c\
	ft_striteri.c\
	ft_strmapi.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_itoa.c\
	ft_lstadd_back_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstmap_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c\

# OBJS: Variable que genera una lista de archivos objeto (.o)                  #
#       a partir de los archivos fuente (.c).                                  #
OBJS = $(SRCS:.c=.o)
# COLORS: Definen secuencias de escape ANSI para colores en la terminal        #                                                                       #
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
# **************************************************************************** #
# **************************************************************************** #
# REGLAS                                                                       #
# $(NAME) : $(OBJS): Esta regla indica que para crear la biblioteca (libft.a), #
#           se necesitan los archivos objeto ($(OBJS)).                        #
#			La acción @ar crs $(NAME) $(OBJS) utiliza el comando ar para crear #
#			un archivo de biblioteca estática (lib.a) con los archivos objeto  #
#			especificados.                                                     #
$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)
# all: Esta regla es un alias para la regla $(NAME).                           #
#      Cuando se ejecuta make all, se crea la biblioteca.                      #
all: $(NAME)
# %.o : %.c: Esta regla indica cómo compilar cada archivo fuente (.c)          #
#            en un archivo objeto (.o).                                        #
#            La acción @$(CC) $(CCFLAGS) -c -o $@ $< utiliza el compilador gcc #
#            con las opciones -Wall -Wextra -Werror para compilar el archivo   #
#            fuente ($<) y generar el archivo objeto ($@).                     #
%.o : %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<
# bonus: Esta regla es para marcar o diferenciar los bonus                     #
bonus: all
# clean: Esta regla elimina los archivos objeto (.o)                           #
#        generados durante la compilación.                                     #
clean:
	@$(RM) $(OBJS)
# fclean: Esta regla elimina la biblioteca (libft.a)                           #
#         y los archivos objeto (.o).                                          #
fclean: clean
	@rm -f $(NAME)
# re: Esta regla es un alias para la secuencia fclean all.                     #
#     Cuando se ejecuta make re, se limpia la compilación anterior             #
#     y se crea la biblioteca nuevamente.                                      #
re: fclean all
# **************************************************************************** #
# **************************************************************************** #
# PSEUDO-OBJETIVOS                                                             #
# PHONY: Indica que all, clean, fclean y re son pseudo-objetivos,              #
#        no archivos reales.                                                   #
.PHONY: all clean fclean re
# **************************************************************************** #