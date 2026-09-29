# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 15:02:20 by vlorenzo           #+#    #+#              #
#    Updated: 2026/05/20 18:23:19 by vlorenzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_DIR = sources

INC_DIR = includes

SRCS = $(addprefix $(SRC_DIR)/, $(notdir $(wildcard $(SRC_DIR)/*.cpp)))

OBJECTS_DIR = objects

OBJS = $(addprefix $(OBJECTS_DIR)/, $(SRCS:$(SRC_DIR)/%.cpp=%.o))

DEPS = $(addprefix $(OBJECTS_DIR)/, $(SRCS:$(SRC_DIR)/%.cpp=%.d))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJECTS_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJECTS_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

clean:
	rm -rf $(OBJECTS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re