/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:25:14 by dalabrad          #+#    #+#             */
/*   Updated: 2025/09/26 17:34:33 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_UTILS_H
# define ARRAY_UTILS_H

//////////////////////////////////
// HEADERS FROM INCLUDED LIBRARIES
//////////////////////////////////

# include "libft.h"
# include "minishell_exec.h"
# include "minishell_parsing.h"
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

////////////////////////////////////////////////
//------STRUCTS---------------------------------
////////////////////////////////////////////////
typedef struct s_cleanup_args	t_cleanup_args;

////////////////////////////////////////////////
//------ARRAY-UTILS-----------------------------
////////////////////////////////////////////////

//  src/array_utils/array_utils.c
void							free_array(char **array);
size_t							array_size(char **array);
void							print_array(char **array);
void							restore_stdio(int in, int out);

////////////////////////////////////////////////
//------MAIN-UTILS------------------------------
////////////////////////////////////////////////

//  src/main_utils.c
void							restore_stdio(int in, int out);
void							reset_cmd_state(t_data *data);
void							main_loop(t_data *data);
void							process_input_line(char *line, t_data *data,
									int in, int out);

////////////////////////////////////////////////
//------HISTORY UTILS---------------------------
////////////////////////////////////////////////
void							print_history(void);

////////////////////////////////////////////////
//------UTILS VALIDATION------------------------
////////////////////////////////////////////////
int								has_invalid_pipe_usage(const char *s);

#endif