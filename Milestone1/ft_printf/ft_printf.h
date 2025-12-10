/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:03:52 by masacco           #+#    #+#             */
/*   Updated: 2025/12/08 17:43:51 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h> //va_
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(unsigned char *str);
int	ft_putnbr(int nb);
int	ft_hex(unsigned int n, char *hex);
int	ft_pointer(unsigned long n, int i);

#endif