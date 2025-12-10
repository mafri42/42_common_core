/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:11:33 by masacco           #+#    #+#             */
/*   Updated: 2025/12/05 18:29:52 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* void to_upper(void *content)
{
	char *str = (char *)content;

	while (*str)
	{
		*str = (char)ft_toupper((unsigned char)*str);
		str++;
	}
}

void del(void *content)
{
	if (content)
		free(content);
}

int main(void)
{
	t_list *node1 = ft_lstnew(ft_strdup("ciao"));
	t_list *node2 = ft_lstnew(ft_strdup("hello"));
	node1->next = node2;
	
	ft_lstiter(node1, to_upper);
	t_list *temp = node1;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	ft_lstclear(&node1, del);
	//free (node1);
	//free (node2);
	return (0);
} */