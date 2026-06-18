/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:33:21 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/01 21:33:21 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* La función ft_isprint verifica si un carácter dado es un carácter imprimible
en el conjunto de caracteres ASCII estándar. Un carácter es imprimible si es
visible y puede ser impreso en pantalla. En el conjunto de caracteres
ASCII estándar, los caracteres imprimibles tienen un valor ASCII entre
32 y 126, inclusive. La función devuelve un valor distinto de cero si
el carácter es imprimible y devuelve 0 si no lo es.
*/
int	ft_isprint(int c)
{
	return ((c > 31) && (c < 127));
}
