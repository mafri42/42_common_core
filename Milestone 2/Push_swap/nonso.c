/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nonso.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:14:57 by masacco           #+#    #+#             */
/*   Updated: 2026/03/12 18:29:58 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_fun(char *s)
{
	int	i;

	i = 0;
	if (!((s[i] == '+' || s[i] == '-') || (s[i] >= '0' && s[i] <= '9')))
		return (1);
	if ((s[i] == '+' || s[i] == '-') && !(s[i + 1] >= '0' && s[i + 1] <= '9'))
		return (1);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	same_nb(t_stack_node *a, long n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	nb_node(t_stack_node **stack, long n)
{
	t_stack_node	*new;
	t_stack_node	*last;

	if (!stack)
		return ;
	new = malloc(sizeof(t_stack_node));
	if (!new)
		return ;
	new->nb = n;
	new->next = NULL;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}