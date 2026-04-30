/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:03:47 by masacco           #+#    #+#             */
/*   Updated: 2026/04/30 19:02:25 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bb_swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int *arr, int n)
{
	int i;
	int j;
	bool swapped;
	
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				bb_swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

int get_mediana(t_stack_node **a)
{
	t_stack_node *tmp;
	int mediana;
	int *array;
	int i;
	
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
	bubbleSort(array, stack_len(*a));
	mediana = array[stack_len(*a) / 2];
	free(array);
	return mediana;
}

void	count_moves(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp_a;
	t_stack_node 	*tmp_b;
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

void algorithm(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *best;
	int mediana = get_mediana(a);

	while(stack_len(*a) > 3) {
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
 