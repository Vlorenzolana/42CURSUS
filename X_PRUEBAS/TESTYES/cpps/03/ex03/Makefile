NAME = NowItIsWeird!

CFLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

SRCS =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp


all: $(NAME)

$(NAME):
	clang++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)
	
fclean: clean

re: fclean all

.PHONY: all clean fclean re