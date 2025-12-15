NAME := libft.a

# **************************************************************************** #
# COMPILER
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
CFLAGS	+= -MMD -MP

# DEBUG MODE
ifeq ($(DEBUG),1)
	CFLAGS += -g3 -fsanitize=address
	LDFLAGS += -fsanitize=address
endif

# VALGRIND MODE
ifeq ($(VALGRIND),1)
	CFLAGS += -g3
endif

# **************************************************************************** #
# DIRECTORIES
SRC_DIR	:= sources/
INC_DIR	:= include/
OBJ_DIR	:= obj/

# SUBDIRS
IS_DIR      := is/
LIST_DIR    := list/
MEM_DIR     := mem/
PUT_DIR     := put/
STR_DIR     := str/
TO_DIR      := to/
GNL_DIR     := gnl/

# FILES
GNL_FILES   := get_next_line.c get_next_line_utils.c
IS_FILES    := ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_isevil.c
LIST_FILES  := ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
               ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
               ft_lstnew_bonus.c ft_lstsize_bonus.c
MEM_FILES   := ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
               ft_memmove.c ft_memset.c
PUT_FILES   := ft_print_pointer.c ft_printf.c ft_putchar_fd.c ft_putendl_fd.c \
               ft_puterr.c ft_putnbr_fd.c ft_putstr_fd.c print_utils.c
STR_FILES   := ft_split.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
               ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
               ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
               ft_strtrim.c ft_substr.c ft_strchr_pos.c
TO_FILES    := ft_atoi_base.c ft_atoi.c ft_itoa.c ft_tolower.c ft_toupper.c

SRC_FILES	:= $(addprefix $(IS_DIR), $(IS_FILES))
SRC_FILES	+= $(addprefix $(LIST_DIR), $(LIST_FILES))
SRC_FILES	+= $(addprefix $(MEM_DIR), $(MEM_FILES))
SRC_FILES	+= $(addprefix $(PUT_DIR), $(PUT_FILES))
SRC_FILES	+= $(addprefix $(STR_DIR), $(STR_FILES))
SRC_FILES	+= $(addprefix $(TO_DIR), $(TO_FILES))
SRC_FILES	+= $(addprefix $(GNL_DIR), $(GNL_FILES))


# INCLUDE FILES
INC_FILES	:= libft get_next_line

# GENERAL FILES
# GENERAL FILES
SRCS	:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS	:= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))
DEPS	:= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.d))

INCS	:= $(addprefix $(INC_DIR), $(addsuffix .h, $(INC_FILES)))

# **************************************************************************** #
# COLOURS: BOLD RGBY
BR	= \033[1;31m
BG	= \033[1;32m
BB	= \033[1;34m
BY	= \033[1;33m
BW	= \033[1;37m

# NO COLOR and CLEAR LINE
NC	= \033[0;39m
CL	= \033[2K

# **************************************************************************** #
# ESSENTIAL RULES

# Default rule to create the library
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@printf "%b" "$(CL) -> $(BW)[Libft]:\t\t$(BG)Compilation success\t✅$(NC)\n"

# Rule to compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@printf "%b" "$(CL) -> $(BW)[Libft]:\t\t$(NC)$<\r"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Rule to clean generated files
clean:
	@rm -rf $(OBJ_DIR)
	@printf "%b" "$(CL) -> $(BW)[Libft]:\t\t$(BG)Objetos limpiados ❎$(NC)\n"

# Rule to clean generated files and the executablle
fclean:
	@$(MAKE) clean > /dev/null
	@rm -rf $(NAME)
	@printf "%b" "$(CL) -> $(BW)[Libft]:\t\t$(BG)Proyecto limpiado 🧹$(NC)\n"

# Rule to recompile from zero. 
re: fclean all

# Rule to compile object files from source files with debug flags
debug:
	@$(MAKE) -s clean
	@$(MAKE) -s DEBUG=1
	@echo " -> $(BW)[Debug]:\t\t$(BB)Debug mode enabled\t🟦$(NC)"

-include $(DEPS)
.PHONY: all clean fclean re debug 
.DEFAULT_GOAL := all

# **************************************************************************** #⏎    