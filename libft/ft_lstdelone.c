/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:38:25 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/03 21:35:27 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
void ft_print_list(t_list *begin_list) {
    t_list *tmp = begin_list;
    while (tmp != NULL) {
        printf("begin_list = %s\n", (char*)tmp->content);
        tmp = tmp->next;
    }
}
	
int	main(void)
{
	char *str = malloc(sizeof(char) * 12);
	strcpy(str, "Hello World");
	t_list *begin_list = ft_lstnew(str);
	char *str1 = malloc(sizeof(char) * 9);
	strcpy(str1, " To All");
	t_list *node1 = ft_lstnew(str1);
	ft_lstadd_back(&begin_list, node1);
	char *str2 = malloc(sizeof(char) * 9);
	strcpy(str2, " Of You");
	t_list *node2 = ft_lstnew(str2);
	ft_lstadd_back(&begin_list, node2);
	ft_print_list(begin_list);
	t_list *tmp_list = begin_list->next;
	ft_lstdelone(begin_list, free);
	ft_print_list(tmp_list);
	ft_lstclear(&tmp_list, free);
	ft_print_list(tmp_list);//SIGSEGV-OutOfBounds
	return (0);
}
*/