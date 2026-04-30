/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:34:30 by masacco           #+#    #+#             */
/*   Updated: 2026/03/25 16:27:01 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointer(unsigned long n, int i)
{
	const char		*hex = "0123456789abcdef";
	unsigned long	len;

	if (!n)
		return (write(1, "(nil)", 5), 5);
	len = 0;
	if (i == 0)
		len += write (1, "0x", 2);
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n >= 16)
		len += ft_pointer(n / 16, 1);
	len += ft_putchar(hex[n % 16]);
	return (len);
}
