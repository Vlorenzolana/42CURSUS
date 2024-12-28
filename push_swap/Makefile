NAME = push_swap

PS_LIB_NAME = push_swap.a

PS_LIB_SOURCES = algo_push_swap.c checks.c comm_push.c \
comm_rev_rotate.c comm_rotate.c comm_swap.c \
create_first_stack.c ft_split.c node_eval.c \
utils_ft_split.c utils_push_swap.c utils_stack.c

MAIN = main.c

PS_LIB_OBJECTS = $(PS_LIB_SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

GREEN = \033[1;32m
ORANGE = \033[38;5;208m
PINK = \033[1;35m
RED = \033[0;31m
RESET = \033[0m

COMPILE_FLAG = .compiled

all: $(PS_LIB_NAME) $(NAME)
	@if [ -f $(COMPILE_FLAG) ]; then \
		echo "$(GREEN)MAKE SUCCESSFUL$(RESET)"; \
		rm -f $(COMPILE_FLAG); \
	else \
		echo "$(ORANGE)NOTHING TO BE DONE$(RESET)"; \
	fi

$(PS_LIB_NAME): $(PS_LIB_OBJECTS)
	ar rcs $(PS_LIB_NAME) $(PS_LIB_OBJECTS)

$(NAME): $(PS_LIB_NAME) $(MAIN)
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(PS_LIB_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@touch $(COMPILE_FLAG)

clean:
	$(RM) $(PS_LIB_OBJECTS)
	@echo "$(PINK)OBJECT FILES CLEAN-UP $(RESET)"

fclean: clean
	$(RM) $(PS_LIB_NAME) $(NAME)
	@echo "$(RED)FULL CLEAN-UP$(RESET)"

re: fclean all

.PHONY: all clean fclean re