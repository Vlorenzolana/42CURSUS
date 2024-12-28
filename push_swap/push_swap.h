/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:34:53 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/28 08:21:41 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*prev;
	int				num;
	int				index;
	int				cost_to_push;
	bool			is_cheapest;
	bool			above_middle;
	struct s_list	*target_node;
	struct s_list	*next;
}	t_stack_node;

int				main(int argc, char **argv);
void			free_stack(t_stack_node **stack);
void			free_str(char **argv);

char			**ft_split(char const *s, char c);
unsigned int	ft_count_frags(const char *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_wordlen(const char *word, char c);
char			**ft_freeall(char **frags, unsigned int k);

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char const *s1, char const *s2);

long			ft_atol(const char *str);
void			add_node(t_stack_node **stack, int num);
t_stack_node	*find_last_node(t_stack_node *node);
void			ft_error(t_stack_node **a, char **argv, bool arg2);
void			create_stack(t_stack_node **a, char **argv, bool arg2);

char			**prepare_argv(char *argv);
bool			check_syntax_error(char *str);
bool			check_interval_error(long num);
bool			check_repetition_error(t_stack_node *a, int nbr);

int				stack_size(t_stack_node *node);
bool			is_sorted(t_stack_node *node);
void			solve_for_three(t_stack_node **a);
t_stack_node	*find_highest(t_stack_node *node);
t_stack_node	*find_lowest(t_stack_node *node);

void			swap(t_stack_node **stack);
void			sa(t_stack_node	**a);
void			sb(t_stack_node	**b);
void			ss(t_stack_node	**a, t_stack_node	**b);

void			push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

void			calculate_price(t_stack_node *a, t_stack_node *b);
void			find_target_node(t_stack_node *a, t_stack_node *b);
void			assign_index(t_stack_node *node);
void			evaluate_nodes(t_stack_node *a, t_stack_node *b);
void			flag_cheapest(t_stack_node *b);

void			push_swap(t_stack_node **a, t_stack_node **b);

bool			both_in_same_half(t_stack_node *b);
t_stack_node	*find_cheapest(t_stack_node *node);
int				find_higher(int n, int m);

#endif