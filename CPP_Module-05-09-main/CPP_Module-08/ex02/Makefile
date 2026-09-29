NAME = MutantStack

COMP = c++
FLAGS = -g -Wall -Wextra -Werror -Weffc++ -std=c++98

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRCS = $(SRC_DIR)/main.cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "\033[32m$(NAME) COMPILED ✔\n\033[0m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(COMP) $(FLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "\033[31mAll objects removed. ✔\r"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31m$(NAME) removed. ✔\r"

re: fclean all

.PHONY: clean fclean re all⏎  