NAME = harl

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD

SRCS = main.cpp Harl.cpp

BUILD_DIR = objects

OBJS = $(addprefix $(BUILD_DIR)/, $(SRCS:.cpp=.o))

DEPS = $(addprefix $(BUILD_DIR)/, $(SRCS:.cpp=.d))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)