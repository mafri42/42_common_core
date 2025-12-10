/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:05:02 by masacco           #+#    #+#             */
/*   Updated: 2025/12/03 13:17:55 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(len * sizeof(char) + 1);
	while (len != 0)
	{
		str[i] = s[start];
		len--;
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/* int main()
{
    char *s = "francesca";
    unsigned int start = 4;
    size_t len = 4;
    
    char *substr = ft_substr(s, start, len);
    if (substr != NULL)
    {
        printf ("%s\n", substr);
        free(substr);
    }
    else
        printf("NULL\n");
} */