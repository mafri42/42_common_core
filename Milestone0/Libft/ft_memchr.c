/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:39:17 by masacco           #+#    #+#             */
/*   Updated: 2025/12/15 11:54:31 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

/* int main()
{
	const char *str = "ciao";
    printf("%s\n", (char *)memchr(str, 'i', 3));
	printf("%s\n", (char *)ft_memchr(str, 'i', 3));
} */