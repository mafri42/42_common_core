/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:20:27 by masacco           #+#    #+#             */
/*   Updated: 2026/02/19 15:35:31 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	char	c;
	int		i;

	i = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		i += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
	{
		c = nb + '0';
		i += write(1, &c, 1);
	}
	return (i);
}

/* int main()
{
	printf(" %d\n", ft_putnbr(1000));
	//printf(" %d\n", ft_putnbr(2147483647));
	//printf(" %d\n", ft_putnbr(-2147483648));
	printf(" %d\n", ft_putnbr(-42));
	printf(" %d\n", ft_putnbr(0));
} */