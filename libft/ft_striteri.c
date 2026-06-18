/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:38:08 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/01 21:38:08 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	str_index;

	if (!s || !f)
		return ;
	str_index = 0;
	while (s[str_index])
	{
		f(str_index, s + str_index);
		str_index++;
	}
}
/* revisar porque lee memoria de donde no debe
    y porque solo convierte en 1 algunos elementos y otros no. USAR EL MOCK QUE TIENE MAPENA EN FT_LSTMAP

void ft_iteri(unsigned int str_index, char *str) {
    printf("str_index -> %u\n", str_index);
    printf("ft_iteri_in -> %s\n", &str[str_index]);
    //str[str_index] = '1';
    printf("ft_iteri_out -> %s\n", &str[str_index]);
}
    
int main(void) {
    char *string = malloc(sizeof(char) * 7);
    strcpy(string, "abcdef");
    ft_striteri(string, &ft_iteri);
    printf("ft_striteri -> %s\n", string);
    return (0);
}
*/