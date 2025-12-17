/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:41:05 by masacco           #+#    #+#             */
/*   Updated: 2025/12/15 13:24:49 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		start;
	int		end;
	int		i;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	new_str = (char *)malloc(end - start + 2);
	if (!new_str)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		new_str[i] = s1[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/* int main()
{
	printf("%s\n", ft_strtrim("xxciaoxx", "x"));
	printf("%s\n", ft_strtrim("xxciao", "x"));
	printf("%s\n", ft_strtrim("ciaoxx", "x"));
	printf("%s\n", ft_strtrim("xxxx", "x"));
} */