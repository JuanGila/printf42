/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:42:14 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/01 21:35:27 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			s_index;
	unsigned char	ptr_c;
	unsigned char	*ptr_s;

	s_index = 0;
	ptr_c = (unsigned char)c;
	ptr_s = (unsigned char *)s;
	while (s_index < n)
	{
		if (ptr_s[s_index] == ptr_c)
			return (ptr_s + s_index);
		s_index++;
	}
	return (NULL);
}
/*
int main() {
	char data[] = "hola mundo";
	char *p = memchr(data, 'm', 10);
	if (p != NULL) printf("Encontrado: %s\n", p);
	else printf("No encontrado\n");
	return (0);
}
*/