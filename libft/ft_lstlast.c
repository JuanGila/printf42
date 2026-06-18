/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:45:18 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/02 20:45:18 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*

void ft_print_list(t_list *begin_list) {
    t_list *tmp = begin_list;
    while (tmp != NULL) {
        printf("begin_list_tmp = %s\n", (char*)tmp->content);
        tmp = tmp->next;
    }
}

int main(void) {
    char *str = malloc(sizeof(char) * 12);
    strcpy(str, "Hello World");
    t_list *begin_list = ft_lstnew(str);
    char *str1 = malloc(sizeof(char) * 8);
    strcpy(str1, " To All");
    ft_lstadd_back(&begin_list, str1);
    char *str2 = malloc(sizeof(char) * 8);
    strcpy(str2, " Of You");
    ft_lstadd_back(&begin_list, str2);
    ft_print_list(begin_list);
    ft_lstclear(&begin_list, free);
	ft_print_list(begin_list);//SIGSEGV-OutOfBounds
    return 0;
}
*/