/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:05:18 by masacco           #+#    #+#             */
/*   Updated: 2026/04/30 19:06:43 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int calc_total_cost(int cost_a, int cost_b)
{
	if (cost_a >= 0 && cost_b >= 0)
		return (ft_max(cost_a, cost_b));
	else if (cost_a < 0 && cost_b < 0)
	{
		cost_a = -cost_a;
		cost_b = -cost_b;
		return (ft_max(cost_a, cost_b));
	}
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}

void ft_target(t_stack_node *a, t_stack_node *tmp, t_stack_node *target)
{
    if (!target)
	{
		tmp = a;
		target = tmp;
		while (tmp)
		{
			if (tmp->nb < target->nb)
				target = tmp;
			tmp = tmp->next;
		}
	}
}

t_stack_node *find_target(t_stack_node *a, long nb)
{
	t_stack_node *tmp;
	t_stack_node *target;
	long best_match;

	tmp = a;
	target = NULL;
	best_match = LONG_MAX;
	while (tmp)
	{
		if (tmp->nb > nb && tmp->nb < best_match)
		{
			best_match = tmp->nb;
			target = tmp;
		}
		tmp = tmp->next;
	}
	if (!target)
	{
		tmp = a;
		target = tmp;
		while (tmp)
		{
			if (tmp->nb < target->nb)
				target = tmp;
			tmp = tmp->next;
		}
	}
	return (target);
}
