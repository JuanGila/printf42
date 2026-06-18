/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 22:47:20 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/04 20:01:30 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (!lst || !f)
		return ;
	current = lst;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}

/*
void ft_print_lstnode(void *content) {
	printf("content = %s\n", (char*)content);
}

int main(void)
{
	char *str = malloc(sizeof(char) * 12);
	strcpy(str, "Hello World");
	t_list *begin_list = ft_lstnew(str);
	char *str1 = malloc(sizeof(char) * 8);
	strcpy(str1, " To All");
	t_list *node1 = ft_lstnew(str1);
	ft_lstadd_back(&begin_list, node1);
	char *str2 = malloc(sizeof(char) * 8);
	strcpy(str2, " Of You");
	t_list *node2 = ft_lstnew(str2);
	ft_lstadd_back(&begin_list, node2);
	ft_lstiter(begin_list, &ft_print_lstnode);
	return (0);
}
*/