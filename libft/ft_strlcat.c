/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 05:05:56 by jgilaber          #+#    #+#             */
/*   Updated: 2026/02/12 05:05:58 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
	{
	size_t	isrc;
	size_t	ldest;
	size_t	lsrc;

	ldest = ft_strlen(dest);
	lsrc = ft_strlen(src);
	isrc = 0;
	if (size <= ldest)
		return (lsrc + size);
	while (src[isrc] != '\0' && isrc < size - ldest - 1)
	{
		dest[ldest + isrc] = src[isrc];
		isrc++;
	}
	dest[ldest + isrc] = '\0';
	return (ldest + lsrc);
}

/*
void ft_do_strlcat(char *test, char *dst, char *src, size_t size) {
	printf("%s -> %zu\n", test, ft_strlcat(dst, src, size));
	printf("dst_result -> %s", dst);
}

int	main(void) {
	char	dst[10] = "Init";
	// Test1 -> Devuelve ¿?
	ft_do_strlcat("Test1", dst, "VeryLongString", 10);
	return (0);
}
*/