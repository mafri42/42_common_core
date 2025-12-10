/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:31:45 by masacco           #+#    #+#             */
/*   Updated: 2025/12/08 17:41:10 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int n, char *hex)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n >= 16)
		len += ft_hex(n / 16, hex);
	len += ft_putchar(hex[n % 16]);
	return (len);
}
