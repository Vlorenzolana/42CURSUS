# The name of the library we are going to create.
NAME = libft.a

# The compiler to use, here it's the C compiler.
CC = cc

CCFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c\
ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
ft_tolower.c ft_toupper.c ft_calloc.c ft_strdup.c ft_putchar_fd.c\
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_substr.c ft_split.c\
ft_striteri.c ft_strmapi.c ft_strjoin.c ft_strtrim.c ft_itoa.c\
get_next_line.c get_next_line_utils.c ft_printf.c print_fn.c\

# Directory where all the object files (.o) will be stored.
OBJS_DIR = objects

# List of object files (.o) generated from source files.
# $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o)) adds the $(OBJS_DIR)/ prefix to every object file.
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# List of source files for the bonus part.
BONUS_SRCS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# List of object files generated from the bonus source files.
BONUS_OBJS = $(addprefix $(OBJS_DIR)/, $(BONUS_SRCS:.c=.o))

# ANSI color codes for colored output in the terminal.
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
RESET = \033[0m

# Default target that will be executed if no target is specified.
all: $(NAME)

# Rule to create the library (archive file).
# $(NAME) depends on all object files (OBJS).
# `ar crs` creates an archive (static library) from the object files.
$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)
	@echo "$(GREEN)-> libft.a COMPILATION OK$(RESET)"

# Rule to compile a source file into an object file.
# %.o will match any object file, %.c will match the corresponding source file.
# $< represents the first dependency (the source file).
# $@ represents the target file (the object file).
$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CCFLAGS) -c -o $@ $<

# Rule to clean the generated object files and directory.
 # Remove the entire object directory
# `@` suppresses the command output.
clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(YELLOW)-> All .o FILES FROM LIBFT REMOVED$(RESET)"

# Rule to clean everything including the library.
# `clean` is called first to remove the object files and directory.
# Remove the generated library file
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)-> libft.a REMOVED$(RESET)"

# Rule to rebuild everything from scratch.
# `fclean` is called first to remove everything and then `all` is called to rebuild.
re: fclean all

# Rule to compile the library with the bonus source files.
# It depends on both the regular object files and the bonus object files.
# `ar crs` will create the final library including the bonus functions.
bonus: $(OBJS) $(BONUS_OBJS)
	@ar crs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(GREEN)-> libft.a WITH BONUSES COMPILATION OK$(RESET)"

# Declares targets that are not actual files.
# This prevents Make from confusing these names with file names.
.PHONY: all clean fclean re bonus