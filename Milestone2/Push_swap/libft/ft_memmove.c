/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:02:58 by masacco           #+#    #+#             */
/*   Updated: 2025/12/06 18:25:57 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	s = (const char *)src;
	d = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (d);
	if (d <= s)
	{
		while (n > 0)
		{
			d[i] = s[i];
			n--;
			i++;
		}
	}
	else
	{
		while (i + 1 <= n--)
			d[n] = s[n];
	}
	return (d);
}

/* int main()
{
	char src[] = "ciao";
	char dst[] = "hello";
	size_t n = 3;

	printf("%s\n", (char *)ft_memmove(dst, src + 2, n));
	printf("%s\n", (char *)memmove(dst, src + 2, n));
} */