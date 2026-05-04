/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 17:44:58 by masacco           #+#    #+#             */
/*   Updated: 2026/05/04 17:45:13 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	calc_total_cost(int cost_a, int cost_b)
{
	if (cost_a >= 0 && cost_b >= 0)
		return (ft_max(cost_a, cost_b));
	else if (cost_a < 0 && cost_b < 0)
	{
		cost_a = -cost_a;
		cost_b = -cost_b;
		return (ft_max(cost_a, cost_b));
	}
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}
