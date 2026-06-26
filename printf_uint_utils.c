//
#include "libft.h"
#include "printflib.h"
////
size_t ft_get_printf_unsigned_int_decimal_flag(va_list *args)//u -> OK
{
	//unsigned int nbr = va_arg(*args, unsigned int);
	char * nbr_itoa = ft_itoa(va_arg(*args, unsigned int));
	ft_putstr_fd(nbr_itoa, 1);
	return (ft_strlen(nbr_itoa));
	return (0);
}
/*
size_t ft_get_printf_lower_hex_unsigned_int_flag(va_list *args)//x -> OK
{
    unsigned int nbr = va_arg(*args, unsigned int);
    char * nbr_itoa = ft_itoa_base(nbr, 16);
    ft_putstr_fd(nbr_itoa, 1);//ft_putstr_fd(ft_tolower(nbr_itoa), 1);
    return (ft_strlen(nbr_itoa));
    return (0);
}

size_t ft_get_printf_upper_hex_unsigned_int_flag(va_list *args)//X -> OK
{
    unsigned int nbr = va_arg(*args, unsigned int);
    char * nbr_itoa = ft_itoa_base(nbr, 16);
    ft_putstr_fd(ft_toupper(nbr_itoa), 1);
    return (ft_strlen(nbr_itoa));
    return (0);
}*/