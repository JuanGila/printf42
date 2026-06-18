/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:41 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/01 21:36:41 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_index;
	size_t	little_index;

	if (!little[0])
		return ((char *)big);
	big_index = 0;
	while (big[big_index] && big_index < len)
	{
		little_index = 0;
		while (big[big_index + little_index] == little[little_index]
			&& big_index + little_index < len)
			little_index++;
		if (!little[little_index])
			return ((char *)(big + big_index));
		big_index++;
	}
	return (NULL);
}

/*void ft_do_strnstr(char *test, char *str, char *to_find, size_t len) {
	printf("%s -> %s\n", test, ft_strnstr(str, to_find, len));
}

en C:
a[i] = *(a + i)
&a[i] = a + i

int	main(void) {
	char str[] = "The fox jumps over the lazy dog";
	// Test1 -> Devuelve: "The fox jumps over the lazy dog"
	ft_do_strnstr("Test1", str, "", 2);
	// Test2 -> Devuelve: "fox jumps over the lazy dog"
	ft_do_strnstr("Test2", str, "fox", 9);
	// Test3 -> Devuelve: (null)
	ft_do_strnstr("Test3", str, "fox", 7);
	return (0);
}
*/