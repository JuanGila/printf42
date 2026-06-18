/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:38:45 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/01 21:38:45 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
        return ;
	while (*s)
		write(fd, s++, sizeof(char));
}
/*
int main(void) {
    ft_putstr_fd("Hello World !", 1);
    return (0);
}
*/