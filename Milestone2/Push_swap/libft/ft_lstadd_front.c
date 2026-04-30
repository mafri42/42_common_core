/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:43:47 by masacco           #+#    #+#             */
/*   Updated: 2025/12/05 16:14:30 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* int main()
{
	char txt[] = "ciao";
	t_list *node = ft_lstnew(txt);
	char txt1[] = "bene";
	t_list *node1 = ft_lstnew(txt1);
	char txt2[] = "come";
	t_list *node2 = ft_lstnew(txt2);
	ft_lstadd_front(&node, node1);
	ft_lstadd_front(&node, node2);
	printf("%p\n", (void *)&node);
	printf("%p\n", (void *)node->next);
	printf("%p\n", (void *)node->next->next);
	printf("%p\n", (void *)node->next->next->next);
	free(node); // ? valgrind leaks
	free(node1); //?
	free(node2); //?
} */