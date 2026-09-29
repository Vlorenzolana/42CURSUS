NAME = Bureaucrat

COMP = c++
FLAGS = -g -Wall -Wextra -Werror -std=c++98

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/Bureaucrat.cpp \
	   $(SRC_DIR)/main.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "\033[32m$(NAME) COMPILED ✔\n\033[0m"
	
	@echo "\033[38;5;65m"
	@echo "  ██████╗██████╗ ██████╗    ██████╗ ███████╗"
	@echo " ██╔════╝██╔══██╗██╔══██╗  ██╔═████╗██╔════╝"
	@echo " ██║     ██████╔╝██████╔╝  ██║██╔██║███████╗"
	@echo " ██║     ██╔═══╝ ██╔═══╝   ████╔╝██║╚════██║"
	@echo " ╚██████╗██║     ██║       ╚██████╔╝███████║"
	@echo "  ╚═════╝╚═╝     ╚═╝        ╚═════╝ ╚══════╝"
	@echo " ==========================================="
	@echo "|     EX00: Bureaucrat      by aamaya-g    |"
	@echo " ==========================================="

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(COMP) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[31mAll objects removed. ✔\r"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) removed. ✔\r"

re: fclean all

.PHONY: clean fclean re all

