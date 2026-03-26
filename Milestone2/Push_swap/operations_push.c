/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:25:44 by masacco           #+#    #+#             */
/*   Updated: 2026/03/10 17:18:12 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node;

	if (!src)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (!*dest)
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		(*dest)->prev = node;
		*dest = node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write (1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	write (1, "pb\n", 3);
}
