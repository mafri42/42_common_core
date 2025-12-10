/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:15:11 by masacco           #+#    #+#             */
/*   Updated: 2025/12/03 12:20:19 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;

	if (!dest && !src)
		return (0);
	if (n == 0 || (dest == src))
		return (dest);
	s1 = (char *)dest;
	s2 = (const char *)src;
	while (n != 0)
	{
		if (*s1 != *s2)
			*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	return (dest);
}

/* int main()
{
    const char    *original = "helloworld";
    size_t  b = 20;
    char    dest[b];

    printf("%s\n", (char *)ft_memcpy(dest, original, b));
} */