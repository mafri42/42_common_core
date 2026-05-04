/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:13:46 by masacco           #+#    #+#             */
/*   Updated: 2026/05/04 17:47:50 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> //int min e int max
# include <stdbool.h> //booleani
# include "./libft/libft.h" //collegare libft

typedef struct s_stack_node //struttura 
{
	long				nb; //numeri perche' gestisce meglio
	int					index; //per la posizione del numero
	int					push_cost; //calcolo per capire quli numeri sposatre nella stack b
	struct s_stack_node	*target;
	struct s_stack_node	*next; // nodo successivo
	struct s_stack_node	*prev; // nodo precedente
}	t_stack_node;

//stack.c
int		stack_nb_order(t_stack_node *stack);
void	stack_a(t_stack_node **a, char **argv);
int		stack_len(t_stack_node *stack);
void	sort_three(t_stack_node **a);
void	free_stack(t_stack_node **stack);

//utils.c ?? rivedere
t_stack_node	*find_target(t_stack_node *a, long nb);
long			ft_atoi_long(const char *nptr);
int				error_fun(char *s);
int				same_nb(t_stack_node *a, long n);
void			nb_node(t_stack_node **stack, long n);
void			print_stack(t_stack_node *stack, char *str);
int				calc_total_cost(int cost_a, int cost_b);

//operations_swap.c
void	swap(t_stack_node **head);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);

//operations_push.c
void	push(t_stack_node **dest, t_stack_node **src);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);

//operations_rotate.c
void	rotate(t_stack_node **stack);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);

//operations_rev_rotate.c
void	rev_rotate(t_stack_node **stack);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);

//algorithm.c
void	algorithm(t_stack_node **a, t_stack_node **b);

//index.c
void	ft_index(t_stack_node **a, t_stack_node **b);

// moves.c
int				rotation_count(t_stack_node **stack, int num);
t_stack_node	*push_count(t_stack_node **a, t_stack_node **b);
void			push_nb(t_stack_node **a, t_stack_node **b, t_stack_node *best);
void			rotate_a(t_stack_node **a);

//ps_ultis.c

//ps_ultis1.c

//ps_ultis2.c


#endif