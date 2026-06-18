/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 05:03:39 by jgilaber          #+#    #+#             */
/*   Updated: 2026/02/12 05:03:42 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i] && i < n - 1) i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
void ft_do_strncmp(char *test, char *s1, char *s2) {
	printf("%s -> %d\n", test, ft_strncmp(s1, s2));
}

int	main(void) {
	char *string1;
	char *string2;
	// Test1 -> Deveria devolver 0.
	string1 = "Juancho Marques";
	string2 = "Juancho Marques";
	ft_do_strncmp("Test1", string1, string2, 11);
	// Test2 -> Devuelve un negativo.
	string1 = "Juaanuho Marque";
	string2 = "Juabnuho Marque";
	ft_do_strncmp("Test2", string1, string2, 8);
	// Test3 -> Devuelve un positivo.
	string1 = "Juabnuho Marque";
	string2 = "Juaanuho Marqu";
	ft_do_strncmp("Test3", string1, string2, 5);
	return (0);
}
*/