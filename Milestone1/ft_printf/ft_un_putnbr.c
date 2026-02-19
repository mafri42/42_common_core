/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:28:09 by masacco           #+#    #+#             */
/*   Updated: 2026/02/19 15:42:55 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_un_putnbr(unsigned int nb)
{
	char	c;
	int		i;

	i = 0;
	if (nb >= 10)
	{
		i += ft_un_putnbr(nb / 10);
		i += ft_un_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		i += write(1, &c, 1);
	}
	return (i);
}
