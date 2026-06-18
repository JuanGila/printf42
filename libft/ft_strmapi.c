/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:37:03 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/01 21:37:03 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strmapi;
	size_t	strmapi_index;

	if (!s || !f)
		return (NULL);
	strmapi = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!strmapi)
		return (NULL);
	strmapi_index = 0;
	while (s[strmapi_index])
	{
		strmapi[strmapi_index] = f(strmapi_index, s[strmapi_index]);
		strmapi_index++;
	}
	strmapi[strmapi_index] = '\0';
	return (strmapi);
}
/*
char	ft_mapi_uppercase_even(unsigned int i, char c) {
	if (i % 2 == 0 && c >= 'a' && c <= 'z') return (c - 32);
	return (c);
}

int main(void) {
    char *string = malloc(sizeof(char) * 7);
    strcpy(string, "abcdef");
    printf("ft_strmapi -> %s", ft_strmapi(string, &ft_mapi_uppercase_even));
    return (0);
}
*/