# **************************************************************************** #
# DIRECTORIES
SRC_DIR		:= sources/
BONUS_DIR	:= bonus/
INC_DIR		:= includes/
OBJ_DIR		:= obj/
OBJ_BONUS_DIR	:= obj_bonus/
LIBFT_DIR	:= ./libft
MLX_DIR		:= ./MLX42
MLX_BUILD	:= $(MLX_DIR)/build

LIBFT_INC_DIR	:= $(LIBFT_DIR)/include/

# **************************************************************************** #
# PROJECT
NAME		:= cub3D
NAME_BONUS	:= cub3D_bonus
LIBFT		:= $(LIBFT_DIR)/libft.a
MLX_LIB		:= $(MLX_BUILD)/libmlx42.a

# **************************************************************************** #
# FILES
SRCS_FILES =	check_utils.c \
				controls.c \
				data_to_game.c \
				draw.c \
				dup_map.c \
				free_utils.c \
				gc.c \
				hooks.c \
				initialize.c \
				load_map_parser.c \
				main.c \
				parse_color.c \
				parse_file.c \
				parse_textures.c \
				raycast.c \
				read_file_to_array.c \
				texture.c \
				utils.c \


SRCS	:= $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS	:= $(addprefix $(OBJ_DIR), $(SRCS_FILES:.c=.o))
DEPS	:= $(OBJS:.o=.d)

# Bonus files
SRCS_BONUS_FILES =	check_utils_bonus.c \
					controls_bonus.c \
					data_to_game_bonus.c \
					draw_bonus.c \
					dup_map_bonus.c \
					free_utils_bonus.c \
					gc_bonus.c \
					hooks_bonus.c \
					initialize_bonus.c \
					load_map_parser_bonus.c \
					main_bonus.c \
					minimap_bonus.c \
					minimap_utils_bonus.c \
					parse_color_bonus.c \
					parse_file_bonus.c \
					parse_textures_bonus.c \
					raycast_bonus.c \
					read_file_to_array_bonus.c \
					texture_bonus.c \
					utils_bonus.c \

SRCS_BONUS	:= $(addprefix $(BONUS_DIR), $(SRCS_BONUS_FILES))
OBJS_BONUS	:= $(addprefix $(OBJ_BONUS_DIR), $(SRCS_BONUS_FILES:.c=.o))
DEPS_BONUS	:= $(OBJS_BONUS:.o=.d)

# **************************************************************************** #
# COMPILER
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -g
CFLAGS	+= -MMD -MP
IFLAGS	:= -I$(INC_DIR) -I$(LIBFT_INC_DIR) -I$(MLX_DIR)/include
LDFLAGS	:= $(LIBFT) $(MLX_LIB) -ldl -lglfw -pthread -lm

# **************************************************************************** #
# COLOURS: BOLD RGBYW
BR	= \033[1;31m
BG	= \033[1;32m
BB	= \033[1;34m
BY	= \033[1;33m
BW	= \033[1;37m

# NO COLOR and CLEAR LINE
NC	= \033[0;39m
CL	= \033[2K

# **************************************************************************** #
# BUILD OPTIONS
-include $(DEPS)
-include $(DEPS_BONUS)

# Default rule
all: libmlx libft $(NAME)

# **************************************************************************** #
# COMPILAR BIBLIOTECAS
libft:
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

libmlx:
	@if [ ! -d "$(MLX_BUILD)" ]; then \
		printf "%b" "-> $(BW)[MLX42]:\t$(BB)Creando build...$(NC)\r"; \
		cmake -S $(MLX_DIR) -B $(MLX_BUILD) > /dev/null; \
	fi
	@printf "%b" "-> $(BW)[MLX42]:\t$(BB)Compilando...$(NC)\r"
	@cmake --build $(MLX_BUILD) -j4 > /dev/null
	@printf "%b" "$(CL)-> $(BW)[MLX42]:\t$(BG)Compilada con éxito ✅$(NC)\n"

# **************************************************************************** #
# COMPILAR PROYECTO
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BG)Compilación exitosa ✅$(NC)\n"
	@echo "─────────────────────────────────────────────────────$(BY)"
	@echo " ░▒▓██████▓▒░ ▒▓█▓▒  ▒▓█▓▒ ▒▓███████▓▒ ▒▓███████▓▒░ ▒▓███████▓▒░  "
	@echo "░▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒      ░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒░ "
	@echo "░▒▓█▓▒░       ▒▓█▓▒  ▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒      ░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒░ "
	@echo "░▒▓█▓▒░       ▒▓█▓▒  ▒▓█▓▒ ▒▓███████▓▒ ▒▓███████▓▒  ▒▓█▓▒  ▒▓█▓▒░ "
	@echo "░▒▓█▓▒░       ▒▓█▓▒  ▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒      ░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒░ "
	@echo "░▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒      ░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒░ "
	@echo " ░▒▓██████▓▒░ ░▒▓██████▓▒░ ▒▓███████▓▒ ▒▓███████▓▒░ ▒▓███████▓▒░  "                                                                                                                   
	@echo "                by aamaya-g and vlorenzo 💪"
	@echo "$(NC)─────────────────────────────────────────────────────"

# **************************************************************************** #
# COMPILAR OBJETOS
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BB)Compiling: $(NC)$<\r"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR):
	@mkdir -p $(OBJ_BONUS_DIR)

$(OBJ_BONUS_DIR)%.o: $(BONUS_DIR)%.c | $(OBJ_BONUS_DIR)
	@mkdir -p $(dir $@)
	@printf "%b" "$(CL) -> $(BW)[$(NAME_BONUS)]:\t$(BB)Compiling: $(NC)$<\r"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# **************************************************************************** #
# BONUS
bonus: libmlx libft $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LDFLAGS) -o $(NAME_BONUS)
	@printf "%b" "$(CL) -> $(BW)[$(NAME_BONUS)]:\t$(BG)Compilación exitosa ✅$(NC)\n"
	@echo "─────────────────────────────────────────────────────$(BY)"
	@echo " ░▒▓██████▓▒░ ▒▓█▓▒  ▒▓█▓▒ ▒▓███████▓▒ ▒▓███████▓▒░ ▒▓███████▓▒░  "
	@echo "░▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒      ░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒░ "
	@echo "░▒▓█▓▒░       ▒▓█▓▒  ▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒      ░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒░ "
	@echo "░▒▓█▓▒░       ▒▓█▓▒  ▒▓█▓▒ ▒▓███████▓▒ ▒▓███████▓▒  ▒▓█▓▒  ▒▓█▓▒░ "
	@echo "░▒▓█▓▒░       ▒▓█▓▒  ▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒      ░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒░ "
	@echo "░▒▓█▓▒░░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒      ░▒▓█▓▒ ▒▓█▓▒  ▒▓█▓▒░ "
	@echo " ░▒▓██████▓▒░ ░▒▓██████▓▒░ ▒▓███████▓▒ ▒▓███████▓▒░ ▒▓███████▓▒░  "
	@echo "             by aamaya-g and vlorenzo 💪 $(BR)[BONUS]$(BY)"
	@echo "$(NC)─────────────────────────────────────────────────────"

# **************************************************************************** #
# LIMPIEZA
clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BG)Objetos limpiados ❎$(NC)\n"

fclean:
	@$(MAKE) clean > /dev/null
	@$(MAKE) fclean -sC $(LIBFT_DIR)
	@rm -rf $(NAME) $(NAME_BONUS) $(OBJ_DIR) $(OBJ_BONUS_DIR) $(MLX_BUILD)
	@printf "%b" "$(CL) -> $(BW)[$(NAME)]:\t$(BG)Proyecto limpiado 🧹$(NC)\n"

re: fclean all

rebonus: fclean bonus

# **************************************************************************** #
.PHONY: all clean fclean re rebonus libmlx libft bonus
.DEFAULT_GOAL := all
