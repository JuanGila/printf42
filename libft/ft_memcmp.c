/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 21:02:52 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/04 21:54:14 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			s_index;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	s_index = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (s_index < n)
	{
		if (ptr_s1[s_index] != ptr_s2[s_index])
			return (ptr_s1[s_index] - ptr_s2[s_index]);
		s_index++;
	}
	return (0);
}
/*
void ft_do_memcmp(
	char *test, char *s1, char *s2, size_t n,
	int (*f)(const void *, const void *, size_t)
){
	printf("%s -> %d\n", test, f(s1, s2, n));
}

int main() {
	char s1[] = {1, 2, 3};
	char s2[] = {1, 2, 4};
	// Test 1 -> Devuelve negativo ya que el byte en s1 es menor que el de s2
	ft_do_memcmp("Test 1", s1, s2, 2, &ft_memcmp);
	// Test 2 -> Devuelve negativo ya que el byte en s1 es mayor que el de s2
	ft_do_memcmp("Test 2", s2, s1, 2, &ft_memcmp);
	// Test 3 -> Devuelve 0 porque 2 = 2
	ft_do_memcmp("Test 3", s1, s2, 1, &ft_memcmp);
}
*/