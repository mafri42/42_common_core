/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msacco <msacco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:16:14 by masacco           #+#    #+#             */
/*   Updated: 2026/05/06 19:58:34 by msacco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_nb_order(t_stack_node *stack, t_stack_node *b)
{
	if (!stack)
		return (1);
	ft_index(&stack, &b);
	while (stack->next != NULL)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_a(t_stack_node **a, char **argv)
{
	int		i;
	long	n;

	n = 0;
	i = 0;
	while (argv[i])
	{
		if (error_fun(argv[i]))
		{
			free_stack(a, NULL);
			write(2, "Error\n", 6);
			return (1);
		}
		n = ft_atoi_long(argv[i]);
		if (n > INT_MAX || n < INT_MIN || same_nb(*a, n))
		{
			free_stack(a, NULL);
			write(2, "Error\n", 6);
			return (1);
		}
		nb_node(a, n);
		i++;
	}
	return (0);
}

int	stack_len(t_stack_node *stack)
{
	int	len;

	len = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	sort_three(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->nb;
	second = (*a)->next->nb;
	third = (*a)->next->next->nb;
	if (first > second && first > third)
		ra(a);
	if (second > first && second > third)
		rra(a);
	first = (*a)->nb;
	second = (*a)->next->nb;
	if (first > second)
		sa(a);
}

void	free_stack(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;
	t_stack_node	*corr;

	if (!a || !*a)
		return ;
	corr = *a;
	while (corr)
	{
		tmp = corr->next;
		free(corr);
		corr = tmp;
	}
	*a = NULL;
	if (!b || !*b)
		return ;
	corr = *b;
	while (corr)
	{
		tmp = corr->next;
		free(corr);
		corr = tmp;
	}
	*b = NULL;
}
