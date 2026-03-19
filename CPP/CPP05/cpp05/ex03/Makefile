NAME = ex03
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       Bureaucrat.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp \
	   Intern.cpp


OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
