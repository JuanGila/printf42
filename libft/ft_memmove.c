/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 02:24:52 by jgilaber          #+#    #+#             */
/*   Updated: 2026/05/29 02:25:31 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (!dest || !src || n == 0)
		return (NULL);
	if (ptr_src < ptr_dest)
	{
		while (n-- > 0)
			ptr_dest[n] = ptr_src[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*ptr_dest_index = n, ptr_src_index = 0;
	while (ptr_dest_index > 0)
	{
		ptr_dest[ptr_dest_index - 1] = ptr_src[ptr_src_index];
		ptr_dest_index--;
		ptr_src_index++;
	}
*/
/*
🧠 ¿Cómo se logra evitar el solapamiento de memoria?
Detectamos si las regiones se pisan:
    Si dest < src → copia de izquierda a derecha
    Si dest > src → copia de derecha a izquierda (evita sobrescritura)

void ft_do_memmove(char *test, char *dst, char *src, size_t size) {
    printf("%s_in -> dest: %s src: %s\n", test, dst, src);
    unsigned char *ptr_memmove = ft_memmove(dst, src, size);
    printf("%s_out -> dest: %s src: %s\n", test, ptr_memmove, src);
}
int main(void) {
    char *s1 = malloc(sizeof(char) * 9);
    strcpy(s1, "1234");
    printf("s1 -> %s\n", s1);
    char *s2 = malloc(sizeof(char) * 5);
    strcpy(s2, "1235");
    printf("s2 -> %s\n", s2);
    ft_do_memmove("Test1_s1", s1, s2, 4);//parece que ok
    //ft_do_memmove("Test2_s2", s2, s1, 4);//parece no ok
    return (0);
}
*/