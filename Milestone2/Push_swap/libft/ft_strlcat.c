/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:19:26 by masacco           #+#    #+#             */
/*   Updated: 2025/12/02 17:34:52 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] && i < size)
	{
		i++;
	}
	if (i == size)
		return (i + ft_strlen(src));
	j = 0;
	while (src[j] && (i + j) < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/* int main()
{
	char dest[] = "ciao";
	char src[] = "come va";

	printf("%zu\n", ft_strlcat(dest, src, 10));
	printf("%zu\n", strlcat(dest, src, 10));
	printf("%s\n", dest);
} */