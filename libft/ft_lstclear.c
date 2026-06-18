/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:29:30 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/08 17:19:28 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_tmp_node;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		lst_tmp_node = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(lst_tmp_node, del);
	}
}

/*
void ft_print_list(t_list *begin_list) {
    t_list *tmp = begin_list;
    while (tmp != NULL) {
        printf("begin_list = %s\n", (char*)tmp->content);
        tmp = tmp->next;
    }
}

int main (void)
{
	char *str = malloc(sizeof(char) * 12);
	strcpy(str, "Hello World");
	t_list *my_list = ft_lstnew(str);
	char *str1 = malloc(sizeof(char) * 8);
	strcpy(str1, " To All");
	ft_lstadd_back(&my_list, ft_lstnew(str1));
	char *str2 = malloc(sizeof(char) * 8);
	strcpy(str2, " Of You");
	ft_lstadd_back(&my_list, ft_lstnew(str2));
	ft_print_list(my_list);
	ft_lstclear(&my_list, free);
	ft_print_list(my_list);//SIGSEGV-OutOfBounds
	return (0);
}
*/