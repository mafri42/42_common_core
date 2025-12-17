/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:06:13 by masacco           #+#    #+#             */
/*   Updated: 2025/12/16 17:09:19 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/* void del(void *content)
{
	free(content);
}

 int main()
{
	t_list *node1 = ft_lstnew(ft_strdup("ciao"));// alloco memoria e creo nodo
	t_list *node2 = ft_lstnew(ft_strdup("hello"));
	node1->next = node2;
	t_list *tmp = node1;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	ft_lstdelone(node1, del);
	node1 = node2;
	printf("%s\n", "deleted:");
	t_list *tmp2 = node1;
	while (tmp2)
	{
		printf("%s\n", (char *)tmp2->content);
		tmp2 = tmp2->next;
	}
	ft_lstdelone(node1, del);
	return (0);	
} */