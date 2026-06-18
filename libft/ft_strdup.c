/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 23:32:12 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/17 17:33:08 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str_dup;
	if (!s)
		return (ft_strdup(""));
	str_dup = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str_dup)
		return (NULL);
	ft_memcpy(str_dup, s, ft_strlen(s));
	str_dup[ft_strlen(s) + 1] = '\0';
	return (str_dup);
}

/* ESTE EJERCICIO NO SE TRASPASA AL DE LA PISCINA CON ft_memcpy
char	*ft_strdup(const char *s)
{
	char	*str_dup;
	size_t	str_index;

	str_dup = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str_dup)
		return (NULL);
	str_index = 0;
	while (s[str_index])
	{
		str_dup[str_index] = s[str_index];
		str_index++;
	}
	str_dup[str_index] = '\0';
	return (str_dup);
}

int main() {
	char original[] = "Hola mundo";
	char *copia = ft_strdup(original);
	printf("Original: %s\n", original);
	printf("Copia: %s\n", copia);
	free(copia);
	return (0);
}
*/