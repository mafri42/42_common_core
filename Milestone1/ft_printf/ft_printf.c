/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:06:25 by masacco           #+#    #+#             */
/*   Updated: 2026/02/19 15:32:17 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(va_list args, char c)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, unsigned char *)));
	else if (c == 'p')
		return (ft_pointer(va_arg(args, unsigned long), 0));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_un_putnbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			len += write(1, format, 1);
		}
		else
		{
			format++;
			len += check_type(args, *format);
		}
		format++;
	}
	va_end(args);
	return (len);
}

/*int main()
{
	int i = 3;
	int y = -3;
	int *j = &i;

	printf("%d\n", ft_printf("%c\n", 'a'));
	printf("%d\n\n", printf("%c\n", 'a'));

	printf("%d\n", ft_printf("%s\n", "ciao"));
	printf("%d\n\n", printf("%s\n", "ciao"));

	printf("%d\n", ft_printf("%p\n", j));
	printf("%d\n\n", printf("%p\n", j));

	printf("%d\n", ft_printf("%d\n", y));
	printf("%d\n\n", printf("%d\n", y));

	printf("%d\n", ft_printf("%i\n", y));
	printf("%d\n\n", printf("%i\n", y));

	printf("%d\n", ft_printf("%u\n", i));
	printf("%d\n\n", printf("%u\n", i));

 	printf("%d\n", ft_printf("%x\n", 0));
	printf("%d\n\n", printf("%x\n", 0));

	printf("%d\n", ft_printf("%X\n", 0));
	printf("%d\n\n", printf("%X\n", 0));
}*/
