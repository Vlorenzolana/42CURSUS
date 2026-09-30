NAME = SedIsForLosers

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp

all: $(NAME)

$(NAME):
	clang++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)
	
fclean: clean

re: fclean all

.PHONY: all clean fclean re