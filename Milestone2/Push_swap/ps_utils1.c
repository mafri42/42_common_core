/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:05:18 by masacco           #+#    #+#             */
/*   Updated: 2026/05/04 17:45:24 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_target(t_stack_node *a, t_stack_node *tmp, t_stack_node *target)
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

void	fun(t_stack_node *tmp, t_stack_node **target)
{
	while (tmp)
	{
		if (tmp->nb < (*target)->nb)
			*target = tmp;
		tmp = tmp->next;
	}
}

t_stack_node	*find_target(t_stack_node *a, long nb)
{
	t_stack_node	*tmp;
	t_stack_node	*target;
	long			best_match;

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
		fun(tmp, &target);
	}
	return (target);
}
