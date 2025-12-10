/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:40:11 by masacco           #+#    #+#             */
/*   Updated: 2025/12/06 19:27:13 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	if (!lst)
		return (NULL);
	last_node = lst;
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}
/* int main()
{
	t_list *node1 = ft_lstnew(ft_strdup("ciao"));
	t_list *node2 = ft_lstnew(ft_strdup("hello"));
	t_list *node3;
	t_list *temp;

	ft_lstadd_back(&node1, node2);
	temp = node1;
	node3 = ft_lstlast(node1);
	printf("%s\n", (char *)node3->content);
	free(node1);
	//free(node2);
	//free(node3);
	return (0);
} */