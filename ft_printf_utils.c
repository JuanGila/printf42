/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:09:34 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/27 22:39:32 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

int	ft_get_printf_d_flag(va_list *args)
{
	return (ft_get_printf_i_flag(args));
}

int	ft_get_printf_i_flag(va_list *args)
{
	int		nbr;
	char	*nbr_itoa;

	nbr = va_arg(*args, int);
	nbr_itoa = ft_itoa(nbr);
	ft_putstr_fd(nbr_itoa, 1);
	return (ft_strlen(nbr_itoa));
}

int	ft_get_printf_u_flag(va_list *args)
{
	unsigned int	nbr;
	unsigned int	nbr_len;
	char			*nbr_itoa;

	nbr = va_arg(*args, unsigned int);
	nbr_itoa = ft_itoa(nbr);
	ft_putstr_fd(nbr_itoa, 1);
	while (nbr_itoa[nbr_len])
		nbr_len++;
	return (nbr_len);
}

/*
size_t ft_get_printf_x_flag(va_list *args)//x -> OK
{
    unsigned int nbr = va_arg(*args, unsigned int);
    char * nbr_itoa = ft_itoa_base(nbr, 16);
    ft_putstr_fd(nbr_itoa, 1);//ft_putstr_fd(ft_tolower(nbr_itoa), 1);
    return (ft_strlen(nbr_itoa));
    return (0);
}

size_t ft_get_printf_X_flag(va_list *args)//X -> OK
{
    unsigned int nbr = va_arg(*args, unsigned int);
    char * nbr_itoa = ft_itoa_base(nbr, 16);
    ft_putstr_fd(ft_toupper(nbr_itoa), 1);
    return (ft_strlen(nbr_itoa));
    return (0);
}*/