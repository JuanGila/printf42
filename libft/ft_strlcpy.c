/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:25:21 by jgilaber          #+#    #+#             */
/*   Updated: 2026/02/09 20:25:26 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	copy_len = src_len;
	if (src_len >= size)
		copy_len = size - 1;
	ft_memcpy(dst, src, copy_len);
	dst[copy_len] = '\0';
	return (src_len);
}
/*
void ft_do_strlcpy(char *src, unsigned int size) {
	char str_dest[50];
	printf("%s\n", str_dest);
	printf("%zu\n", ft_strlcpy(str_dest, src, size));
}

int	main(void) {
	char string[] = "Juancho Marques";
	ft_do_strlcpy(string, 0);// Mostrara ¿?
	ft_do_strlcpy(string, 7);// Mostrara Juancho y 6
	ft_do_strlcpy(string, 20);// Mostrara Juancho Marques\0\0\0\0\0
	return (0);
}
*/