/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:06:15 by masacco           #+#    #+#             */
/*   Updated: 2026/04/29 19:12:23 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_index(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *tmp_a;
	t_stack_node *tmp_b;
	int	index;
	
	tmp_a = *a;
	tmp_b = *b;
	index = 0;
	if (!a)
		return ;
	while (tmp_a)
	{
		tmp_a->index = index;
		tmp_a = tmp_a->next;
		index++;
	}
	index = 0;
	if (!b)
		return ;
	while (tmp_b)
	{
		tmp_b->index = index;
		tmp_b = tmp_b->next;
		index++;
	}
}
