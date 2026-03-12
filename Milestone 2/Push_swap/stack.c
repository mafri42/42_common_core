/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:16:14 by masacco           #+#    #+#             */
/*   Updated: 2026/03/12 18:25:38 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_nb_order(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL) //finche' non sono finiti i numeri
	{
		if (stack->nb > stack->next->nb) //se il numero che stiamo guardando e' piu' grande del numero dopo
			return (0); //ritorno nel main, esco
		stack = stack->next; //guardo il numero dopo e rifa' i controlli
	}
	return (1);
}

void	stack_a(t_stack_node **a, char **argv)
{
	int		i;
	long	n;

	n = 0;
	i = 0;
	while (argv[i])
	{
		if (error_fun(argv[i]))
		{
			free_stack(a);
			write(2, "Error\n", 6);
			exit(1);
		}
		n = ft_atoi_long(argv[i]);
		if (n > INT_MAX || n < INT_MIN || same_nb(*a, n))
		{
			free_stack(a);
			write(2, "Error\n", 6);
			exit(1);
		}
		nb_node(a, n);
		i++;
	}
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
		return (1);
	first = (*a)->nb;
	second = (*a)->next->nb;
	third = (*a)->next->next->nb;
	if (first > second && first > third)
		ra(&a);
	if (second > first && second > third)
		rra(&a);
	first = (*a)->nb;
	second = (*a)->next->nb;
	if (first > second)
		sa(&a);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*corr;
	
	if (!stack || !*stack)
		return ;
	corr = *stack;
	while (corr)
	{
		tmp = corr->next;
		free(corr);
		corr = tmp;
	}
	*stack = NULL;
}