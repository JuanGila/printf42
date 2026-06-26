/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:09:34 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/24 19:12:40 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

size_t	ft_get_printf_int_decimal_flag(va_list *args)//d -> OK
{
	return (ft_get_printf_base_int_flag(args));
}

size_t	ft_get_printf_base_int_flag(va_list *args)//i -> OK
{
	//int nbr = va_arg(*args, int);
	char * nbr_itoa = ft_itoa(va_arg(*args, int));
	ft_putstr_fd(nbr_itoa, 1);
	return (ft_strlen(nbr_itoa));
	return (0);
}