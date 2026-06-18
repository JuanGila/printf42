/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:40:59 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/02 20:40:59 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size_count;

	if (lst == NULL)
		return (0);
	size_count = 0;
	while (lst != NULL)
	{
		size_count++;
		lst = lst->next;
	}
	return (size_count);
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
    char *str = malloc(sizeof(char) * 15);
    strcpy(str, "Hello World To");
    t_list *begin_list = ft_lstnew(str);
    char *str1 = malloc(sizeof(char) * 12);
    strcpy(str1, " All Of You");
    ft_lstadd_back(&begin_list, str1);
    ft_print_list(begin_list);
    ft_lstclear(&begin_list, free);
	ft_print_list(begin_list);//SIGSEGV-OutOfBounds
    return 0;
}
*/