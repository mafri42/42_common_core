/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:10:09 by masacco           #+#    #+#             */
/*   Updated: 2026/05/08 12:54:47 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotation_count(t_stack_node **stack, int num)
{
	int				count;
	int				nb_stack;
	int				nb_index;
	t_stack_node	*tmp;

	count = 0;
	tmp = *stack;
	nb_stack = stack_len(*stack);
	while (num-- > 0)
		tmp = tmp->next;
	nb_index = tmp->index;
	if (nb_index <= (nb_stack / 2))
		while (count < nb_index)
			count++;
	else
	{
		while (nb_index < nb_stack)
		{
			count--;
			nb_index++;
		}
	}
	return (count);
}

t_stack_node	*push_count(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp_b;
	t_stack_node	*target;
	t_stack_node	*best_node;
	int				best_moves;
	int				current_moves;

	tmp_b = *b;
	best_node = NULL;
	best_moves = INT_MAX;
	while (tmp_b)
	{
		target = find_target(*a, tmp_b->nb);
		tmp_b->target = target;
		current_moves = calc_total_cost(target->push_cost, tmp_b->push_cost);
		if (current_moves < best_moves)
		{
			best_moves = current_moves;
			best_node = tmp_b;
		}
		tmp_b = tmp_b->next;
	}
	return (best_node);
}

void	func(t_stack_node **a, t_stack_node **b, int cost_a, int cost_b)
{
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
}

void	push_nb(t_stack_node **a, t_stack_node **b, t_stack_node *best)
{
	int	cost_a;
	int	cost_b;

	cost_a = best->target->push_cost;
	cost_b = best->push_cost;
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	func(a, b, cost_a, cost_b);
	pa(a, b);
}

void	rotate_a(t_stack_node **a)
{
	t_stack_node	*tmp;
	t_stack_node	*min;

	tmp = *a;
	min = tmp;
	while (tmp)
	{
		if ((int)tmp->nb < min->nb)
			min = tmp;
		tmp = tmp->next;
	}
	while (!stack_nb_order(*a, NULL))
	{
		if (min->index <= stack_len(*a))
			ra(a);
		else
			rra(a);
	}
}
