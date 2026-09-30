NAME = libft.a
SRCS			=	$(wildcard ./src/ft*.c)
OBJS			= $(SRCS:.c=.o)				

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RESET = \033[0m

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "$(YELLOW)Compiling libft.a...$(RESET)"
				@ar rcs $(NAME) $(OBJS)
				@echo "$(GREEN)libft.a created successfully.$(RESET)"

%.o: %.c
	
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
				@echo "$(YELLOW)Deleting all the object files for libft.a...$(RESET)"
				@$(RM) $(OBJS)
				@echo "$(GREEN)All the object files for libft.a deleted succesfully.$(RESET)"

fclean:			clean
				@echo "$(YELLOW)Deleting libft.a...$(RESET)"
				@$(RM) $(NAME)
				@echo "$(GREEN)libft.a deleted succesfully.$(RESET)"

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus