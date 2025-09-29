
NAME := phonebook
SRC := 	main.cpp \
		PhoneBook.cpp \
		Contact.cpp \

CXX = c++
RM := rm -rf
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRC:%.cpp=%.o)

all : $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS):%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re