/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:40:39 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/16 20:52:01 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	str_index;

	str_index = 0;
	while (s[str_index])
		str_index++;
	return (str_index);
}

/*
int	main(void) {
	char string[16] = "Juancho Marques";
	printf("Test1 -> %lld\n", ft_strlen(string));
	return (0);
}
*/