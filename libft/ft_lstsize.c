/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 20:40:59 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/19 21:21:51 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size_count;

	if (!lst)
		return (0);
	size_count = 0;
	while (lst != NULL)
	{
		size_count++;
		lst = lst->next;
	}
	return (size_count);
}
