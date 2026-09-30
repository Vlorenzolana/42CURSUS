NAME = InterfaceAndRecap

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRCS =	main.cpp \
		AMateria.cpp \
		MateriaSource.cpp \
		Ice.cpp \
		Cure.cpp \
		Character.cpp \
  
OBJS =	main.o \
		AMateria.o \
		MateriaSource.o \
		Ice.o \
		Cure.o \
		Character.o \

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re