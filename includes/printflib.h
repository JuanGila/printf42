/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 21:40:06 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/24 21:46:29 by jgilaber         ###   ########.fr       */
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
////
size_t ft_get_printf_char_flag(va_list *args);
size_t ft_get_printf_string_flag(va_list *args);
size_t ft_get_printf_pointer_flag(va_list *args);
size_t ft_get_printf_int_decimal_flag(va_list *args);
size_t ft_get_printf_base_int_flag(va_list *args);
size_t ft_get_printf_unsigned_int_decimal_flag(va_list *args);
size_t ft_get_printf_lower_hex_unsigned_int_flag(va_list *args);
size_t ft_get_printf_upper_hex_unsigned_int_flag(va_list *args);
/*
int ft_printf(const char *restrict format, ...);
int		ft_printf(const char *format, ...);
int		ft_print_char(int c);
int		ft_print_str(char *s);
int		ft_print_nbr(int n);
int		ft_print_uint(unsigned int n);
int		ft_print_hex(unsigned int n);
int		ft_print_hex_upper(unsigned int n);
int		ft_print_pointer(void *p);
*/
#endif