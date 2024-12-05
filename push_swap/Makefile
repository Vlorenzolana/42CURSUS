# The name of the executable
NAME = push_swap

# The name of the static library
PS_LIB_NAME = push_swap.a

# Source files for the static library
PS_LIB_SOURCES = argv_checks.c ft_split.c ft_split_utils.c initial_stack_creation.c \
swap_command.c push_command.c rotate_command.c reverse_rotate_command.c \
push_swap_algorythm.c node_evaluations.c stack_utils.c push_swap_utils.c

# Main source file
MAIN = main.c

# Object files derived from the source files
PS_LIB_OBJECTS = $(PS_LIB_SOURCES:.c=.o)

# Compiler settings
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# ANSI escape codes for colors
GREEN = \033[1;32m
RED = \033[1;31m
YELLOW = \033[1;33m
RESET = \033[0m

# Helper variable to check if compilation was done
COMPILE_FLAG = .compiled

# The main build target, checks if compilation is needed
all: $(PS_LIB_NAME) $(NAME)
	@if [ -f $(COMPILE_FLAG) ]; then \
		echo "$(GREEN)PUSH_SWAP COMPILATION SUCCESSFUL$(RESET)"; \
		rm -f $(COMPILE_FLAG); \
	else \
		echo "$(YELLOW)NOTHING TO BE DONE$(RESET)"; \
	fi

# Create the static library from object files
$(PS_LIB_NAME): $(PS_LIB_OBJECTS)
	ar rcs $(PS_LIB_NAME) $(PS_LIB_OBJECTS)

# Link the main executable with the library
$(NAME): $(PS_LIB_NAME) $(MAIN)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(PS_LIB_NAME)

# Compile object files from source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@touch $(COMPILE_FLAG)

# Clean up object files
clean:
	$(RM) $(PS_LIB_OBJECTS)
	@echo "$(RED)OBJECT FILES DELETED$(RESET)"

# Full cleanup: removes object files, library, and executable
fclean: clean
	$(RM) $(PS_LIB_NAME) $(NAME)
	@echo "$(RED)EXECUTABLE AND LIBRARY FILES DELETED$(RESET)"

# Rebuild the entire project
re: fclean all

# Declare phony targets (targets that are not files)
.PHONY: all clean fclean re