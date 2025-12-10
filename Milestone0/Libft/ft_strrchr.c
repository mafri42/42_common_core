/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:38:31 by masacco           #+#    #+#             */
/*   Updated: 2025/11/26 15:46:02 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/* int main()
{
	char *res = ft_strrchr("ciaoixiaio", 'i');
	if (res != NULL)
		printf("%s\n", res);
	else
		printf("NULL\n");
	printf("%s\n", strrchr("ciaoixiaio", 'i'));
} */