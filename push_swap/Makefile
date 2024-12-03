NAME = push_swap
CHECKER_NAME = checker

CC = cc -g3

CFLAGS = #-Wall -Wextra -Werror

SRCS =	main.c \
		utils.c \
		utils2.c \
		create_node.c \
		ft_split.c \
		ft_atoi.c \
		ft_atol.c \
		ft_isdigit.c \
		ft_free.c



OBJS	= ${SRCS:.c=.o}
CHECKER_OBJS = ${CHECKER_SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

${CHECKER_NAME}: ${CHECKER_OBJS}
		${CC} ${CFLAGS} ${CHECKER_OBJS} -o ${CHECKER_NAME}

clean:
	rm -f ${OBJS}

clean_checker:
	rm -f $(CHECKER_OBJS)

fclean: clean
	rm -f ${NAME}

fclean_checker: clean_checker
		@rm -f ${CHECKER_NAME}

fclean_all: clean fclean_checker
	@rm -f ${CHECKER_NAME}

re: fclean all

re_checker: fclean_checker checker

.PHONY: all clean fclean re