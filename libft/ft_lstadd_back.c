/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:39:05 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/17 19:28:41 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	//ft_lstlast(*lst)->next = new;
}

/*
void ft_print_list(t_list *begin_list) {
    t_list *tmp = begin_list;
    while (tmp != NULL) {
        printf("begin_list = %s\n", (char*)tmp->content);
        tmp = tmp->next;
    }
}

int main(void) {
    char *str = malloc(sizeof(char) * 12);
    strcpy(str, "Hello World");
    t_list *begin_list = ft_lstnew(str);
    char *str1 = malloc(sizeof(char) * 8);
    strcpy(str1, " To All");
    ft_lstadd_back(&begin_list, ft_lstnew(str1));
    char *str2 = malloc(sizeof(char) * 8);
    strcpy(str2, " Of You");
    ft_lstadd_back(&begin_list, ft_lstnew(str2));
    ft_print_list(begin_list);
    ft_lstclear(&begin_list, free);
	ft_print_list(begin_list);//SIGSEGV-OutOfBounds
    return 0;
}
*/