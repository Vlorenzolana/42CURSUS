# ─────────────────────────────────────────────────────────────
# MAKEFILE
# ─────────────────────────────────────────────────────────────

NAME = minishell

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

AU_LIB = ./inc/array_utils.a
AU_SRCS = src/array_utils/array_utils.c
AU_OBJS = $(AU_SRCS:.c=.o)

MINISHELL_EXEC_LIB = ./inc/minishell_exec.a 
EXEC_SRCS = ./src/built-ins/builtin_cd.c \
			./src/built-ins/builtin_echo.c \
			./src/built-ins/builtin_env.c \
			./src/built-ins/builtin_exit.c \
			./src/built-ins/builtin_export.c \
			./src/built-ins/builtin_pwd.c \
			./src/built-ins/builtin_unset.c \
			./src/built-ins/export_no_args.c \
			./src/built-ins/get_exit_code.c \
			./src/built-ins/is_builtin.c \
			./src/cmd_execution/cmd_type_utils.c \
			./src/cmd_execution/command_exec.c \
			./src/cmd_execution/execute_pipeline.c \
			./src/cmd_execution/file_redirections.c \
			./src/cmd_execution/find_path.c \
			./src/cmd_execution/one_command_pipeline.c \
			./src/cmd_execution/pipeline_processes.c \
			./src/cmd_execution/cmd_exec_utils.c \
			./src/cmd_execution/one_builtin_with_redir.c \
			./src/environment/shell_envp_array_create.c \
			./src/environment/shell_envp_array_resync.c \
			./src/environment/shell_envp_array_utils.c \
			./src/environment/shell_envp_attribute_getters.c \
			./src/environment/shell_envp_list_create.c \
			./src/environment/shell_envp_list_utils_1.c \
			./src/environment/shell_envp_list_utils_2.c \
			./src/environment/shell_envp_list_utils_3.c \
			./src/environment/shell_envp_list_utils_4.c \
			./src/environment/shell_envp_set.c \
			./src/error_messages/error_message.c \
			./src/minishell_data/minishell_data.c \
			./src/main_utils.c \

EXEC_OBJS = $(EXEC_SRCS:.c=.o)

MINISHELL_PARSING_LIB = ./inc/minishell_parsing.a
PARSING_SRCS =  ./src/parsing/ft_clasifyTokens.c \
				./src/parsing/ft_expand.c \
				./src/parsing/ft_minisplit.c \
				./src/parsing/ft_minisplit2.c \
				./src/parsing/ft_process_segments.c \
				./src/parsing/tokens_to_cmd.c \
				./src/parsing/tokens_to_cmd1.c \
				./src/parsing/tokens_to_cmd2.c \
				./src/parsing/tokens_to_cmd3.c \
				./src/parsing/tokens_to_cmd4.c \
				./src/parsing/util_expands.c \
				./src/parsing/utils_clean.c \
				./src/parsing/utils_expands2.c \
				./src/parsing/utils_expands3.c \
				./src/parsing/utils_expands4.c \
				./src/parsing/utils_heredoc.c \
				./src/parsing/utils_heredoc2.c \
				./src/parsing/utils_heredoc3.c \
				./src/parsing/utils_init.c \
				./src/parsing/utils_init2.c \
				./src/parsing/utils_parsing.c \
				./src/parsing/utils_token2.c \
				./src/parsing/utils_tokens.c \
				./src/parsing/utils_validation.c \

PARSING_OBJS = $(PARSING_SRCS:.c=.o)

MINISHELL_SIGNALS_LIB = ./inc/minishell_signals.a
SIGNALS_SRCS = ./src/signals/signals.c
SIGNALS_OBJS = $(SIGNALS_SRCS:.c=.o)

MAIN_SRCS = main.c src/banner.c

# ─────────────────────────────────────────────────────────────
# COMPILER
# ─────────────────────────────────────────────────────────────

CC = cc
CFLAGS = -g3 -Iinc -Ilibft/inc -Wall -Wextra -Werror
LDFLAGS = -lreadline -lncurses

# ─────────────────────────────────────────────────────────────
# MAKE ALL DEFAULT TARGET
# ─────────────────────────────────────────────────────────────

all: $(NAME)

# ─────────────────────────────────────────────────────────────
# BUILD EXEC
# ─────────────────────────────────────────────────────────────

$(NAME): $(LIBFT) $(AU_LIB) $(MINISHELL_EXEC_LIB) $(MINISHELL_PARSING_LIB) $(MINISHELL_SIGNALS_LIB) $(MAIN_SRCS)
	@echo "$(YELLOW)Compiling ./minishell executable...$(RESET)"
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN_SRCS) \
		-Wl,--start-group \
			$(MINISHELL_EXEC_LIB) \
			$(MINISHELL_PARSING_LIB) \
			$(AU_LIB) \
			$(MINISHELL_SIGNALS_LIB) \
			$(LIBFT) \
		-Wl,--end-group \
		$(LDFLAGS)
	@echo "$(GREEN)./minishell executable created successfully.$(RESET)"
	
# ─────────────────────────────────────────────────────────────
# GDB DEBUGGING V VLORENZO
# ─────────────────────────────────────────────────────────────

debugv: CFLAGS += -DDEBUG
debugv: all
	@echo "$(BLUE)Binary compiled for GDB debugging (Main test).$(RESET)"

# ─────────────────────────────────────────────────────────────
# GDB TESTING
# ─────────────────────────────────────────────────────────────

gdb: clean all debugv
	@echo "$(BLUE)Lanzando GDB con ./minishell...$(RESET)"
	@if [ -f gdbinit_v.gdb ]; then \
		echo "$(YELLOW)Cargando script de breakpoints: gdbinit_v.gdb$(RESET)"; \
		gdb -x gdbinit_v.gdb ./minishell; \
	else \
		gdb ./minishell; \
	fi

# ─────────────────────────────────────────────────────────────
# COMPILING OBJECTs AND LIBRARIES
# ─────────────────────────────────────────────────────────────

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(AU_LIB): $(AU_OBJS)
	@echo "$(YELLOW)Compiling array_utils.a library...$(RESET)"
	@ar rcs $(AU_LIB) $(AU_OBJS)
	@echo "$(GREEN)array_utils.a created successfully.$(RESET)"

$(MINISHELL_PARSING_LIB): $(PARSING_OBJS)
	@echo "$(YELLOW)Compiling minishell_parsing.a library...$(RESET)"
	@ar rcs $(MINISHELL_PARSING_LIB) $(PARSING_OBJS)
	@echo "$(GREEN)minishell_parsing.a created successfully.$(RESET)"

$(MINISHELL_EXEC_LIB): $(EXEC_OBJS)
	@echo "$(YELLOW)Compiling minishell_exec.a library...$(RESET)"
	@ar rcs $(MINISHELL_EXEC_LIB) $(EXEC_OBJS)
	@echo "$(GREEN)minishell_exec.a created successfully.$(RESET)"

$(MINISHELL_SIGNALS_LIB): $(SIGNALS_OBJS)
	@echo "$(YELLOW)Compiling minishell_signals.a library...$(RESET)"
	@ar rcs $(MINISHELL_SIGNALS_LIB) $(SIGNALS_OBJS)
	@echo "$(GREEN)minishell_signals.a created successfully.$(RESET)"

# ─────────────────────────────────────────────────────────────
# CLEAN
# ─────────────────────────────────────────────────────────────

clean:
	@echo "$(YELLOW)Deleting all the object files...$(RESET)"
	@$(RM) $(EXEC_OBJS) $(PARSING_OBJS) $(SIGNALS_OBJS) $(AU_OBJS) $(BANNER_OBJS) .minishell_history
	@make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)All the object files deleted successfully.$(RESET)"

# ─────────────────────────────────────────────────────────────
# FCLEAN
# ─────────────────────────────────────────────────────────────

fclean: clean
	@echo "$(YELLOW)Deleting the object files, *.a and executable file...$(RESET)"
	@$(RM) $(MINISHELL_EXEC_LIB) $(MINISHELL_PARSING_LIB) $(MINISHELL_SIGNALS_LIB) $(AU_LIB) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Everything deleted successfully.$(RESET)"

# ─────────────────────────────────────────────────────────────
# RE
# ─────────────────────────────────────────────────────────────

re: fclean all

# ─────────────────────────────────────────────────────────────
# RUN
# ─────────────────────────────────────────────────────────────

run: re
	./minishell

# ─────────────────────────────────────────────────────────────
# VALGRIND TESTING
# ─────────────────────────────────────────────────────────────

VALGRIND_FLAGS = -s --leak-check=full --show-leak-kinds=all --track-fds=yes

valgrind: all clean
	@echo "$(BLUE)Ejecutando Valgrind con ./minishell...$(RESET)"
	valgrind $(VALGRIND_FLAGS) ./minishell

.PHONY: all clean fclean re testv testd debugv gdbv valgrind
