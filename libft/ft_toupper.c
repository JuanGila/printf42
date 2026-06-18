/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:00 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/01 21:36:00 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}

/*
void ft_do_str_is_uppercase(char *test, char *str) {
	printf("%s -> %d\n", test, ft_toupper(str));
}

int main(void) {
    // Test1 -> Devuelve 0
	ft_do_str_is_lowercase("Test1", 'a');
	// Test2 -> Devuelve 1
	ft_do_str_is_lowercase("Test2", "A");
	// Test3 -> Devuelve 0
	ft_do_str_is_lowercase("Test3", "Ac");
    return (0);
}
*/