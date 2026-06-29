/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 21:41:54 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/19 21:23:05 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_mapped;
	t_list	*lst_tmp_node;

	if (!lst || !f || !del)
		return (NULL);
	lst_mapped = NULL;
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
