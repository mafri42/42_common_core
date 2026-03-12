/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:13:46 by masacco           #+#    #+#             */
/*   Updated: 2026/03/12 18:09:18 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h> //int min e int max
# include <stdbool.h> //booleani
# include "./libft/libft.h" //collegare libft

typedef struct s_stack_node //struttura
{
	long	nb; //numeri perche' gestisce meglio
	int		index; //per la posizione del numero
	int		push_cost; //calcolo per capire quli numeri sposatre nella stack b
	bool	up_media; // per quelli sopra la media
	bool	cheapest; // riguardo push_cost, il nodo che pusherai
	struct s_stack_node	*target; // nodo che mi attacco dalla stack a alla b o viceversa
	struct s_stack_node	*next; // nodo successivo
	struct s_stack_node	*prev; // nodo precedente
}	t_stack_node;

int		stack_nb_order(t_stack_node *stack);
void	stack_a(t_stack_node **a, char **argv);
int		stack_len(t_stack_node *stack);
void	sort_three(t_stack_node **a);

long	ft_atoi_long(const char *nptr);

void	swap(t_stack_node **head);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);

void	push(t_stack_node **dest, t_stack_node **src);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);

void	rotate(t_stack_node **stack);
void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);

void	rev_rotate(t_stack_node **stack);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);


#endif