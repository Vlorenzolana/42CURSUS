.SILENT:
#for cleaning up messages in Terminal,
#use it instead of "@" a the begining of each line
#containing "$", "make" or "echo"

NAME = fdf

CC = cc

FLAGS = -Wall -Wextra -Werror -g3
LFLAGS = -Iinclude -ldl -lglfw -pthread -lm

SRC_DIR = sources/
SRC = $(shell find ./sources -iname "*.c")
OBJ := ${SRC:%.c=%.o}

LIB = MLX/build/libmlx42.a $(LFLAGS) libft/libft.a
LIBMLX  := ./MLX


YELLOW = \033[1;33m
PURPLE_HIGH = \e[0;105m
GREEN_HIGH = \e[0;102m
RESET = \033[0m

all: libft libmlx42 $(NAME)
	echo "$(GREEN_HIGH) FDF COMPLETE >> WHOLE COMPILATION OK$(RESET)"

$(NAME):$(OBJ)
	$(CC) $(FLAGS) $(LFLAGS) $(OBJ) $(LIB) -o $(NAME)
	echo "$(PURPLE_HIGH) FDF COMPILED OK$(RESET)"

$(OBJ):%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

libmlx42:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	echo "$(YELLOW)-> MLX42.a COMPILATION OK$(RESET)"

libft:
	make -C ./libft -s
	echo libft.a COMPILATION OK

clean:
	rm -rf $(OBJ)
	make clean -C ./libft
	rm -rf $(LIBMLX)/build
	echo CLEAN OK

fclean:clean
	rm -f $(NAME)
	make fclean -C ./libft
	echo "$(RED)-> fdf removed$(RESET)"

re:fclean all

.PHONY: all clean fclean libft libmlx42 re 