/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:03:47 by masacco           #+#    #+#             */
/*   Updated: 2026/05/04 16:47:17 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bb_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int *arr, int n)
{
	int		i;
	int		j;
	bool	swapped;

	i = 0;
	while (i < n - 1)
	{
		swapped = false;
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				bb_swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
			j++;
		}
		if (swapped == false)
			break ;
		i++;
	}
}

int	get_mediana(t_stack_node **a)
{
	t_stack_node	*tmp;
	int				mediana;
	int				*array;
	int				i;

	tmp = *a;
	i = 0;
	array = malloc((stack_len(*a) + 1) * sizeof(int));
	while (tmp)
	{
		array[i] = (int)tmp->nb;
		tmp = tmp->next;
		i++;
	}
	array[i] = '\0';
	bubble_sort(array, stack_len(*a));
	mediana = array[stack_len(*a) / 2];
	free(array);
	return (mediana);
}

void	count_moves(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp_a;
	t_stack_node	*tmp_b;
	int				index;

	tmp_a = *a;
	tmp_b = *b;
	index = -1;
	while (++index < stack_len(*a))
	{
		tmp_a->push_cost = rotation_count(a, index);
		tmp_a = tmp_a->next;
	}
	index = -1;
	while (++index < stack_len(*b))
	{
		tmp_b->push_cost = rotation_count(b, index);
		tmp_b = tmp_b->next;
	}
}

void	algorithm(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*best;
	int				mediana;

	mediana = get_mediana(a);
	while (stack_len(*a) > 3)
	{
		if ((*a)->nb > mediana)
			pb(a, b);
		else
		{
			pb(a, b);
			rb(b);
		}
	}
	if (stack_len(*a) == 3)
		sort_three (a);
	while (*b)
	{
		ft_index(a, b);
		count_moves(a, b);
		best = push_count(a, b);
		push_nb(a, b, best);
	}
	ft_index(a, b);
	rotate_a(a);
}
