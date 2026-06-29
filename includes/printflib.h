/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:40:06 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/27 22:35:46 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFLIB_H
# define PRINTFLIB_H
// #includes para free, es el que falta.
# include <stdio.h>//printf(para test)
# include <unistd.h>//write
# include <stdlib.h>//malloc
# include <stdarg.h>//va_start, va_arg, va_copy, va_end
# include <stddef.h>//size_t
# include <stdint.h>//uintptr_t
# include <limits.h>
# include "libft.h"
////
typedef struct s_printf_flag_handler
{
	char	specifier;
	int		(*func)(va_list *args);
}	t_printf_flag_handler;


int	ft_get_printf_c_flag(va_list *args);
int	ft_get_printf_s_flag(va_list *args);
int	ft_get_printf_p_flag(va_list *args);
int	ft_get_printf_d_flag(va_list *args);
int	ft_get_printf_i_flag(va_list *args);
int	ft_get_printf_u_flag(va_list *args);
int	ft_get_printf_x_flag(va_list *args);
int	ft_get_printf_X_flag(va_list *args);

#endif