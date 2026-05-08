/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:13:43 by masacco           #+#    #+#             */
/*   Updated: 2026/05/08 12:53:39 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp_a;
	t_stack_node	*tmp_b;
	int				index;

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

int	trim(char **argv, t_stack_node **a)
{
	char	**num;
	int		i;
	int		ret;

	ret = 0;
	num = ft_split(argv[1], ' ');
	if (stack_a(a, num))
		ret = 1;
	i = 0;
	while (num[i])
		i++;
	i--;
	while (i >= 0)
	{
		free(num[i]);
		i--;
	}
	free(num);
	return (ret);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if ((argc < 2) || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		if (trim(argv, &a))
			return (1);
	}
	else
		if (stack_a(&a, argv + 1))
			return (1);
	if (!stack_nb_order(a, b))
	{
		if (stack_len(a) == 2)
			sa (&a);
		if (stack_len(a) == 3)
			sort_three (&a);
		else
			algorithm(&a, &b);
	}
	free_stack(&a, &b);
}
