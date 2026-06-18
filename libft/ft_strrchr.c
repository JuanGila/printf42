/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:36:30 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/01 21:36:30 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	c_chr;
	size_t	str_len;

	str = (char *)s;
	c_chr = (char) c;
	str_len = ft_strlen(s);
	if (!c)//poner -> !c_chr
		return (&str[str_len]);
	while (str[--str_len])
	{
		if (str[str_len] == c_chr)
			return (&str[str_len]);
	}
	return (NULL);
}

/*
int main() {
    char c = '\0';//z
    char str[16] = "Juancho Marques";
    printf("%s\n", ft_strrchr(str, c));
    return 0;
}
*/