/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:38:54 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/01 21:38:54 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{//revisar si guille contiene mi linea 25 -> if (nbr < 0) ya que copie su nbr, si no la tiene y n es 0 peta el codigo porque haces 0 = -0
	long	nbr;
	char	c;

	if ((!n && n != 0) || fd < 0)
		return ;
	nbr = n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	write(fd, &c, 1);
}

/*
int main(void) {
    ft_putnbr_fd(-2147483648, 1);
    return (0);
}
*/