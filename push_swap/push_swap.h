/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:34:53 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/30 09:43:11 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	int				index;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
	bool			cheapest;
	bool			top_half;
}					t_node;

int					main(int argc, char **argv);
void				free_stack(t_node **stack);
void				free_str(char **argv);

char				**tidy_arg(char *argv);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strjoin(char const *s1, char const *s2);

char				**ft_split(char const *s, char c);
unsigned int		ft_count_frags(const char *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_wordlen(const char *word, char c);
char				**ft_freeall(char **frags, unsigned int k);

void				create_stack(t_node **a, char **argv, bool arg2);
long				ft_atol(const char *str);
void				fill_node(t_node **stack, int num);
t_node				*find_last(t_node *node);
void				ft_error(t_node **a, char **argv, bool arg2);

bool				check_syntax_error(char *str);
bool				check_interval_error(long num);
bool				check_repetition_error(t_node *a, int nbr);

int					stack_size(t_node *node);
t_node				*is_highest(t_node *node);
t_node				*is_lowest(t_node *node);
void				sort_three(t_node **a);
bool				sorted(t_node *node);

void				push(t_node **dest, t_node **src);
void				pa(t_node **a, t_node **b);
void				pb(t_node **b, t_node **a);

void				swap(t_node **stack);
void				sa(t_node **a);
void				sb(t_node **b);
void				ss(t_node **a, t_node **b);

void				rotate(t_node **stack);
void				ra(t_node **a);
void				rb(t_node **b);
void				rr(t_node **a, t_node **b);

void				reverse_rotate(t_node **stack);
void				rra(t_node **a);
void				rrb(t_node **b);
void				rrr(t_node **a, t_node **b);

void				eval_cost(t_node *a, t_node *b);
void				cost_calculation(t_node *a, t_node *b);
void				this_half(t_node *node);
void				get_target(t_node *a, t_node *b);
void				flag_cheapest(t_node *b);

bool				same_half(t_node *b);
t_node				*get_cheapest(t_node *node);
int					get_higher(int n, int m);

void				push_swap(t_node **a, t_node **b);

#endif