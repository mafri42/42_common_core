/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:51:05 by masacco           #+#    #+#             */
/*   Updated: 2025/12/03 13:14:19 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		tot;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tot = nmemb * size;
	if (tot / nmemb != size)
		return (NULL);
	ptr = malloc(tot);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, tot);
	return (ptr);
}

/* int main ()
{
	int *arr = (int *)ft_calloc(5, 4);
	int i = 0;

	while (i < 5)
	{
		printf("%d", arr[i]);
		i++;
	}
	printf("\n");
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	i = 0;
	while (i < 5)
	{
		printf("%d", arr[i]);
		i++;
	}
	printf ("\n");
	free(arr);
} */