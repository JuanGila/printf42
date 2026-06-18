/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:32:35 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/03 22:18:17 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	return (((c > 64 && c < 91) || (c > 96 && c < 123)));
}

/*
void ft_do_ft_isalpha(char *test, int c) {
	printf("%s -> %d\n", test, ft_isalpha(str));
}

int	main(void) {
	ft_do_ft_isalpha("Test1", '0');
	ft_do_ft_isalpha("Test1", 'J');
	return (0);
}
*/