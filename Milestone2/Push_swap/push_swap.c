/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:13:43 by masacco           #+#    #+#             */
/*   Updated: 2026/03/12 18:10:13 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	while ((argc < 2) || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_a (&a, argv + 1);
	if (!stack_nb_order(a)) //se e' 1 quindi sono ordinati esce e non entra, altrimenti entra e fa gli altri controlli
	{
		if (stack_len(a) == 2)
			sa (&a);
		if (stack_len(a) == 3)
			sort_three (&a);
		else
			ft_algorithm(&a, &b);
	}
	free_stack(&a);
	return (0);
}
