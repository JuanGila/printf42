/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 22:38:14 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/09 19:39:03 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	if (size == 0 || nmemb == 0)
	{
		ptr = malloc(1);
		return (ptr);
	}
	if (size > ((size_t) - 1) / nmemb)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}
/* Este main creo que falla, no se si hace ft_bzero bien.
int	main(void) {
	int *w = (int *) ft_calloc(5, sizeof(int));
	for (size_t i = 0; i < 5; i++) printf("w -> %d\n", w[i]);
	int *x = (int *) ft_calloc(5, sizeof(char));
	for (size_t j = 0; j < 5; j++) printf("x -> %d\n", x[j]);
	return (0);
}
*/