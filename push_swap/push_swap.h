/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlorenzo <vlorenzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:59:58 by vlorenzo          #+#    #+#             */
/*   Updated: 2024/12/05 15:52:18 by vlorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Definir variables tipo struct (listas) y todas las funciones y librerias.
#include <unistd.h> // de momento no lo usamos, pero general
#include <stdio.h> // para print
#include <string.h> // para string
#include <limits.h> // para limites
#include <stdlib.h> // para malloc y free
#include <stdbool.h> // para booleanas

// Definición de la estructura t_node para una lista circular.
typedef struct s_node
{
	int content;
	struct s_node *next;
}	t_node;

//Crea un nuevo nodo (new) con un valor dado y lo inicializa como circular.
t_node *create_node(t_node *lst, int content);

//Crea un nuevo nodo (new) en a cabeza.
t_node *ft_addfront(t_node *head, int content);

//Agrega un nuevo nodo (new) al final de una lista enlazada.
void	ft_lstadd_back(t_node **lst, t_node *new);

//Crea un nuevo nodo (new) para una lista enlazada.
t_node	*ft_lstnew(int content);

//swap 1ª por 2ª
void	ft_swap(t_node *stack);

//push desde StackA/B(get) a StackB/A(give)
void	ft_push(t_node **stack_get, t_node **stack_give);

//Parte el string de caracteres de argumentos por los espacios
char	**ft_split(const char *s, char c);

//Convierte caracteres a integers
int		ft_atoi(const char *str);

//Convierte Integers a Long (para que el checkeo de limites no desborde)
long	ft_atol(const char *str);

//libera strings
void	ft_free(char **string);

//Comprueba si es digito
int		ft_isdigit(int i);

//Comprueba si repetido
//bool check_repeat(int *num);
bool check_repeat(int *num, int size);

//Chequea los argumentos
int check_arg(const char *str);

//Pasa el array lst_str de string char a un array de string integer
int * ft_patoi(char *argv, int *patoi, int *z);

// Printea los stack
void	print_stack(t_node *stack, int z);

//
#endif