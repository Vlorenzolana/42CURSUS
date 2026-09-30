NAME = Megaphone

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Megaphone.cpp

all: $(NAME)

$(NAME):
	clang++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)
	
fclean: clean

re: fclean all

.PHONY: all clean fclean re