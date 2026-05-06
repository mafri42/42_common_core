/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacco <msacco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:13:46 by masacco           #+#    #+#             */
/*   Updated: 2026/05/06 19:57:56 by msacco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include "./libft/libft.h"

typedef struct s_stack_node
{
	long				nb;
	int					index;
	int					push_cost;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//algorithm.c
void			bb_swap(int *a, int *b);
void			bubble_sort(int *arr, int n);
int				get_mediana(t_stack_node **a);
void			count_moves(t_stack_node **a, t_stack_node **b);
void			algorithm(t_stack_node **a, t_stack_node **b);

//push_swap.c
void			ft_index(t_stack_node **a, t_stack_node **b);

// moves.c
int				rotation_count(t_stack_node **stack, int num);
t_stack_node	*push_count(t_stack_node **a, t_stack_node **b);
void			func(t_stack_node **a, t_stack_node **b, int cost_a, int cost_b);
void			push_nb(t_stack_node **a, t_stack_node **b, t_stack_node *best);
void			rotate_a(t_stack_node **a);

//operations_push.c
void			push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);

//operations_rev_rotate.c
void			rev_rotate(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

//operations_rotate.c
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);

//operations_swap.c
void			swap(t_stack_node **head);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

//ps_ultis.c
long			ft_atoi_long(const char *nptr);
int				error_fun(char *s);
int				same_nb(t_stack_node *a, long n);
void			nb_node(t_stack_node **stack, long n);
void			print_stack(t_stack_node *stack, char *str);

//ps_ultis1.c
void			ft_target(t_stack_node *a, t_stack_node *tmp, t_stack_node *target);
void			fun(t_stack_node *tmp, t_stack_node **target);
t_stack_node	*find_target(t_stack_node *a, long nb);

//ps_ultis2.c
int				ft_abs(int n);
int				ft_max(int a, int b);
int				calc_total_cost(int cost_a, int cost_b);

//stack.c
int				stack_nb_order(t_stack_node *stack, t_stack_node *b);
int				stack_a(t_stack_node **a, char **argv);
int				stack_len(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			free_stack(t_stack_node **a, t_stack_node **b);

#endif