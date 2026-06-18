/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 20:48:10 by jgilaber          #+#    #+#             */
/*   Updated: 2026/05/28 20:48:10 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			ptr_index;

	if (!dest || !src)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	ptr_index = 0;
	while (ptr_index < n)
	{
		ptr_dest[ptr_index] = ptr_src[ptr_index];
		ptr_index++;
	}
	return (dest);
}
/*
int main() {
    char origen[] = "Hooolllaaa";
    char destino[10];
    ft_memcpy(destino, origen, 5);
    printf("%s\n", destino);
    return 0;
}
*/