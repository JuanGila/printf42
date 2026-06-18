/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:08 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/01 21:36:08 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}

/*
void ft_do_tolower(char *test, char *str) {
	printf("%s -> %d\n", test, ft_tolower(str));
}

int main(void) {
    // Test1 -> Devuelve 0
	ft_do_tolower("Test1", 'a');
	// Test2 -> Devuelve 1
	ft_do_tolower("Test2", "A");
	// Test3 -> Devuelve 0
	ft_do_tolower("Test3", "Ac");
    return (0);
}
*/