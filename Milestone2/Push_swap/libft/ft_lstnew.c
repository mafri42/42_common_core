/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:42:35 by masacco           #+#    #+#             */
/*   Updated: 2025/12/05 16:14:15 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* int main()
{
	char txt[] = "ciao";
	t_list *node = ft_lstnew(txt);
	char txt1[] = "bene";
	t_list *node1 = ft_lstnew(txt1);
	printf("%s\n", (char *)node->content);
	printf("%p\n", (void *)node->next);
	printf("%s\n", (char *)node1->content);
	printf("%p\n", (void *)node1->next);
	free(node);
	free(node1);
} */