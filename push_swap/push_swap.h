/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:34:53 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 21:34:56 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

/*	T_STACK_NODE STRUCTURE 

This is the data structure that will form the stack to be sorted.
Contains all necessary metadata to evaluate the optimal move and sort
the initial stack following the "game rules".

*previous		Link to previous node in stack.
number 			Number to be sorted.
curr_index		Current position in the stack.
cost_to_push	Cost to push this particular node from stack b to stack a.
is_cheapest		Flags cheapest node to push.
above_median 	Flags whether this node is nearer to top or bottom of stack.
*target_node	The node on top of which this node must be pushed.
*next			Link to next node in stack.									*/

typedef struct s_list
{
	struct s_list	*previous;
	int				number;
	int				index;
	int				cost_to_push;
	bool			is_cheapest;
	bool			above_middle;
	struct s_list	*target_node;
	struct s_list	*next;
}	t_stack_node;

//	MAIN.C
int				main(int argc, char **argv);
void			error_free(t_stack_node **a, char **argv, bool argc_is_2);
void			free_stack(t_stack_node **stack);
void			free_argv(char **argv);

//	FT_SPLIT.C
char			**ft_split(char const *s, char c);
unsigned int	ft_count_frags(const char *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_wordlen(const char *word, char c);
char			**ft_freeall(char **frags, unsigned int k);

//	FT_SPLIT_UTILS.C
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strjoin(char const *s1, char const *s2);

//	INITIAL_STACK_CREATION.C
void			create_stack(t_stack_node **a, char **argv, bool argc_is_2);
long			ft_atol(const char *str);
void			add_node(t_stack_node **stack, int number);
t_stack_node	*find_last_node(t_stack_node *node);
char			**prepare_argv(char *argv);

//	ARGV_CHECKS.C
bool			check_syntax_error(char *str);
bool			check_interval_error(long number);
bool			check_repetition_error(t_stack_node *a, int nbr);

//	STACK_UTILS.C
int				stack_size(t_stack_node *node);
bool			is_sorted(t_stack_node *node);
void			solve_for_three(t_stack_node **a);
t_stack_node	*find_highest(t_stack_node *node);
t_stack_node	*find_lowest(t_stack_node *node);

//	SWAP_COMMAND.C
void			swap(t_stack_node **stack);
void			sa(t_stack_node	**a);
void			sb(t_stack_node	**b);
void			ss(t_stack_node	**a, t_stack_node	**b);

//	PUSH_COMMAND.C
void			push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

//	ROTATE_COMMAND.C
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

//	REVERSE_ROTATE_COMMAND.C
void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//	NODE_EVALUATIONS.C
void			calculate_price(t_stack_node *a, t_stack_node *b);
void			find_target_node(t_stack_node *a, t_stack_node *b);
void			assign_index(t_stack_node *node);
void			evaluate_nodes(t_stack_node *a, t_stack_node *b);
void			flag_cheapest(t_stack_node *b);

//	PUSH_SWAP_ALGORYTHM.C
void			push_swap(t_stack_node **a, t_stack_node **b);

//	PUSH_SWAP_UTILS.C
bool			both_in_same_half(t_stack_node *b);
t_stack_node	*find_cheapest(t_stack_node *node);
int				find_higher(int n, int m);

#endif