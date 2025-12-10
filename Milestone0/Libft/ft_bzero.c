/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:06:41 by masacco           #+#    #+#             */
/*   Updated: 2025/12/06 15:45:23 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str = '\0';
		str++;
	}
}

/* int main()
{
    char str[] = "hello world";
	int i = 0;
	ft_bzero((void *)str, 5);
	while (i < 11)
	{
		if (!str[i])
			printf("index a zero = %d\n", i);
		else
			printf("index normali = %c\n", str[i]);
		i++;
	}
} */