/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:54:18 by masacco           #+#    #+#             */
/*   Updated: 2025/12/16 17:17:56 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

/* int main()
{
	t_list *head = NULL;
	t_list *node1 = ft_lstnew("ciao");
	t_list *node2 = ft_lstnew("hello");
	head = node1;
	ft_lstadd_back(&head, node2);
	t_list *tmmp = head;
	while(tmmp)
	{
		printf("%s\n", (char *)tmmp->content);
		tmmp = tmmp->next;
	}
	free(node1);
	free(node2);
} */