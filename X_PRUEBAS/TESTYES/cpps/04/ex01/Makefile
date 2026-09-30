NAME = IDonNotWantToSetTheWorldOnFire

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =	main.cpp \
		Animal.cpp \
		Brain.cpp \
		Dog.cpp \
		Cat.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp

OBJS =	main.o \
		Animal.o \
		Brain.o \
		Dog.o \
		Cat.o \
		WrongAnimal.o \
		WrongCat.o

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re