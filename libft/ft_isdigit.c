/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:32:57 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/03 22:19:05 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

/*
void ft_do_ft_isdigit(char *test, char *str) {
	printf("%s -> %d\n", test, ft_isdigit(str));
}

int main() {
	ft_do_ft_isdigit("Test1", "01");
	ft_do_ft_isdigit("Test1", "Ab");
    return (0);
}
*/