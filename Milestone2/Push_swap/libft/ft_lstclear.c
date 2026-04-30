/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:07:11 by masacco           #+#    #+#             */
/*   Updated: 2025/12/16 21:35:42 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*temp;

	if (lst == NULL || del == NULL)
		return ;
	node = *lst;
	while (node != NULL)
	{
		temp = node->next;
		ft_lstdelone(node, del);
		node = temp;
	}
	*lst = NULL;
}

/* void	del(void *content)
{
	free(content); //va commentato? bho
}
 int main(void)
{
	t_list *head = ft_lstnew(strdup(" World"));
	t_list *newnode = ft_lstnew(strdup("Hello"));

	ft_lstadd_front(&head, newnode);

	t_list *temp = head;
	while (temp)
	{
		printf("%s", (char *)temp->content);
		temp = temp->next;
	}
	printf("\n");


	ft_lstclear(&head, del);


	if (head == NULL)
		printf("List cleared successfully.\n");
	else
		printf("List not cleared.\n");

	return 0;
} */