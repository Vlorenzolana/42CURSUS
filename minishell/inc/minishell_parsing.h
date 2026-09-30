/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalabrad <dalabrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:21:52 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/26 21:11:46 by dalabrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSING_H
# define MINISHELL_PARSING_H

//////////////////////////////////
// HEADERS FROM INCLUDED LIBRARIES
//////////////////////////////////

# include "array_utils.h"
# include "libft.h"
# include "minishell_exec.h"
# include "minishell_signals.h"
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

//////////////////////////////////
//-----MINISHELL PROMTP----------
//////////////////////////////////

# define PROMPT "minishell>>"
# define HD_TEMPLATE "/tmp/minishell_hd_XXXXXX"

//////////////////////////////////
//-----STRUCTURES----------------
//////////////////////////////////

typedef struct s_cmd	t_cmd;
typedef struct s_data	t_data;
typedef struct s_tokens	t_tokens;
typedef struct s_env	t_env;

// ENUM TOKENS STRUCT
typedef enum t_TokenType
{
	RED_IN,
	RED_OUT,
	HEREDOC,
	APPEND_OUT,
	OPTION,
	COMMAND,
	SETTING,
	PATH,
	ARG,
	ERROR
}						t_TokenType;

// PIPES
typedef struct s_pipes
{
	char				*str;
	size_t				index;
	struct s_pipes		*next;
}						t_pipes;

// UTILS_TOKENS
typedef struct s_qctx
{
	bool				in_s;
	bool				in_d;
	int					*was_quoted;
}						t_qctx;

typedef struct s_exctx
{
	const char			*s;
	t_env				*env;
	char				**out;
}						t_exctx;

// QUOTE TYPE
typedef enum e_quote_type
{
	NO_QUOTE = 0,
	DOUBLE_QUOTE,
	SINGLE_QUOTE
}						t_quote_type;

// TOKENS
typedef struct s_tokens
{
	int					was_quoted;
	int					s_quoted;
	int					d_quoted;
	int					skip;
	char				*str;
	t_TokenType			type;
	t_quote_type		quote_type;
	struct s_tokens		*next;
}						t_tokens;

// COMMS
typedef struct s_comms
{
	t_tokens			*token;
	int					i;
	struct s_comms		*next;
}						t_comms;

// MINI-SPLIT STRUCT
typedef struct s_split
{
	char				**split;
	const char			*s;
	char				c;
}						t_split;

// STRUCTURA DE CLEANUP ARGS
typedef struct s_cleanup_args
{
	char				**segments;
	t_tokens			**tokens;
	size_t				count;
}						t_cleanup_args;

//////////////////////////////////
//-----------FUNCTIONS----------//
//////////////////////////////////

// UTILS INIT & HANDLE
t_tokens				*new_token(char *str);
t_cmd					*new_cmd(void);
int						handle_token_alloc_fail(char **segments, char *line);
t_pipes					*init_struct(t_pipes *args);
int						init_pipe_segments(char *line, char ***segments,
							size_t *n);
t_tokens				**init_tokens_by_segment(size_t count);
void					print_history(void);

// UTILS CLEAN STRUCTS
int						is_exit_command(char **line, t_data *data);
t_pipes					*clean_struct(t_pipes *args);
void					free_tokens_list(t_tokens *head);
void					cleanup(char **segments, t_tokens **tokens, size_t n);
void					free_cmd_list(t_cmd *cmd);

// FT-MINI-SPLIT
char					**ft_minisplit(const char *s, char c, size_t *n);
size_t					splitted_len(const char *s, char c);
char					**split2array(const char *s, char c, char **array,
							size_t w_count);
size_t					is_open(const char *s);
size_t					count_splitted(char *s, char c);
size_t					quoted_field_len(const char *s, char c);

// UTILS PARSING
int						is_path(const char *str);
int						process_backslash(const char *s, size_t *i, int dq,
							char **out);
const char				*skip_space(const char *s);
int						is_escaped(const char *s, int i, int in_single);
void					update_quote_state(char c, int *in_s, int *in_d,
							int prev_escape);

// FT_CLASIFY TOKENS
t_TokenType				clasify_token(const char *str);
void					set_command_type(t_tokens *tokens);
const char				*token_type_str(t_TokenType type);
int						is_token_sep(char c);
void					handle_quotes(char c, bool *in_s, bool *in_d,
							int *quoted);

// UTILS_TOKENS
t_tokens				*create_token(const char *input, size_t *k,
							size_t *i_words);
char					*poly_substr(const char *s, size_t *i, int *was_quoted);
t_tokens				*check_args_fixed(const char *input, size_t *i_words);

// PROCESS BY SEGMENT OR PIPE
void					process_segments(char **segments, t_tokens **tokens,
							size_t n, t_data *data);

// TOK_TO_CMD
t_cmd					*tokens_to_cmd(t_tokens *tokens, t_env *env);
int						append_arg(t_cmd *cmd, const char *arg,
							t_quote_type quote_type, size_t *i);
int						is_arglike(t_tokens *t);
int						is_redir_tok(t_tokens *t);
int						handle_in_redir(t_cmd *cmd, t_tokens **tokens);
int						fill_cmd_args(t_cmd *cmd, t_tokens *t, t_env *env);
int						handle_redirs_and_heredoc(t_cmd *cmd, t_tokens **tokens,
							t_env *env);
int						handle_out_redir(t_cmd *cmd, t_tokens **tokens);
int						set_file_out(t_cmd *cmd, const char *path,
							t_quote_type quote_type, int append);
int						set_file_in(t_cmd *cmd, const char *path,
							t_quote_type quote_type);
int						strip_outer_by_type(char *s, int quote_type);
void					strip_quotes_inplace(char *str);
int						expect_next_token(t_tokens **tokens);
int						next_is_filename(t_tokens *t);

// FT_EXPAND
void					expand_tokens(t_tokens *head, t_env *env);
int						ex_bs_plain(const char *s, size_t *i, char **out);
int						ex_bs_in_dq(const char *s, size_t *i, char **out);
int						handle_exit_status(char **out, int status);
size_t					handle_variable(const char *s, size_t i, char **out,
							t_env *env);
int						is_operator(const t_tokens *t);

// UTILS EXPAND
int						ex_toggle_quotes(const char *s, size_t *i, int *sq,
							int *dq);
int						process_dollar(const char *s, size_t *i, char **out,
							t_env *env);
int						append_char(char **out, char c);
char					*ft_strjoin_char_free(char *s, char c);
int						handle_exit_status(char **out, int status);
size_t					handle_variable(const char *s, size_t i, char **out,
							t_env *env);
int						ex_bs_plain(const char *s, size_t *i, char **out);
int						ex_bs_in_dq(const char *s, size_t *i, char **out);
int						ex_handle_dollar(const char *s, size_t *i, char **out,
							t_env *env);

// UTILS HEREDOC
char					*expand_core(const char *s, t_env *env);
char					*expand_variables(const char *s, t_env *env);
int						ft_strappend(char **dest, const char *src);
int						hd_expand_line(char **p, t_env *env);
char					*hd_add_nl(char *s);
int						run_heredoc(const char *delim, int quoted, t_env *env);
int						heredoc_loop_open(const char *delim, int quoted,
							t_env *env);
int						heredoc_loop(int fd, const char *delim, int quoted,
							t_env *env);
void					heredoc_eof_warning(const char *delim);

// GET TOKENS EVERYWHEREEEEEE
t_tokens				*get_tokens(void);

#endif