/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:13:28 by masacco           #+#    #+#             */
/*   Updated: 2025/12/16 17:11:53 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

/* int main()
{
	t_list *node1 = ft_lstnew("ciao");
	t_list *node2 = ft_lstnew("hello world");

	node1->next = node2;
	printf("%d\n", ft_lstsize(node1));
	free(node1);
	free(node2);
} */