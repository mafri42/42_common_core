/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masacco <masacco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:12:35 by masacco           #+#    #+#             */
/*   Updated: 2025/12/06 17:14:01 by masacco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}

/* static void ft_del(void *content)
{
	free (content);
}
static void *ft_lower(void *content)
{
    char *str = (char *)content;
    char *lowered;
    int i = 0;

    lowered = malloc(strlen(str) + 1);
    if (!lowered)
        return NULL;
    while (str[i] != '\0') {
        lowered[i] = (char)ft_tolower((int)str[i]);
        i++;
    }
    lowered[i] = '\0';
    return lowered;
}
int main()
{
	t_list *head = NULL;
	t_list *new_node;
	t_list *new_node1;
	t_list *temp;
	t_list *new_list;

	char *content1 = "A";
	char *content2 = "B";
	new_node = ft_lstnew((void *)content1);
	ft_lstadd_back(&head, new_node);
	new_node1 = ft_lstnew((void *)content2);
	ft_lstadd_back(&head, new_node1);
	temp = head;
	while (temp)
    {
        printf("%s\n", (char *)temp->content);
        temp = temp->next;
    }
	new_list = ft_lstmap(head, ft_lower, ft_del);
	while (new_list)
    {
        printf("%s\n", (char *)new_list->content);
        new_list = new_list->next;
    }
} */