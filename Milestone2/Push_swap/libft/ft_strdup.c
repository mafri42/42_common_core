/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 19:09:37 by masacco           #+#    #+#             */
/*   Updated: 2025/11/26 19:13:42 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/* int	main()
{
	char	*original = "yo";
	char	*duplicate = ft_strdup(original);
	
	if (duplicate != NULL)
	{
		printf("%s\n", original);
		printf("%s\n", duplicate); 
        printf("%s\n", strdup(duplicate));
		free(duplicate);
	}
	else
		printf("NULL\n");
} */