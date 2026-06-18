/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 21:41:54 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/03 21:41:54 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_mapped;
	t_list	*lst_tmp_node;

	if (!lst || !f || !del)
		return (NULL);
	lst_mapped = malloc(sizeof(t_list) * ft_lstsize(lst));
	if (!lst_mapped)
		return (NULL);
	while (lst != NULL)
	{
		lst_tmp_node = ft_lstnew(f(lst->content));
		if (!lst_tmp_node)
		{
			ft_lstclear(&lst_mapped, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_mapped, lst_tmp_node);
		lst = lst->next;
	}
	return (lst_mapped);
}

/*
static void *ft_lst_map_f(void *content)
{
    char *str;
    char *new_str;
    int i;

    if (!content)
        return (NULL);
    str = (char *)content;
    new_str = malloc(strlen(str) + 1);
    if (!new_str)
        return (NULL);
    i = 0;
    while (str[i])
    {
        new_str[i] = str[i] + 1;
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

void ft_print_list(t_list *begin_list) {
	t_list *tmp = begin_list;
	while (tmp != NULL) {
		printf("begin_list = %s\n", (char*)tmp->content);
		tmp = tmp->next;
	}
}

int main(void) {
	char *str = malloc(sizeof(char) * 12);
	strcpy(str, "1");
	t_list *begin_list = ft_lstnew(str);
	char *str1 = malloc(sizeof(char) * 8);
	strcpy(str1, "2");
	ft_lstadd_back(&begin_list, ft_lstnew(str1));
	ft_print_list(begin_list);
	ft_lstmap(begin_list, ft_lst_map_f, free);
	ft_print_list(begin_list);
	ft_lstclear(&begin_list, free);
	//ft_print_list(begin_list);//SIGSEGV-OutOfBounds
	return (0);
}*/