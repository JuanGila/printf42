// 42 Header
#include "ft_printf.h"
/*
void ft_putstr_fd(char *s, int fd)
{
    while (*s)
        write(fd, s++, 1);
}
size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return (i);
}

////
size_t ft_get_printf_int_decimal_flag(va_list *args)//d -> OK
{
    //return (ft_get_printf_base_int_flag(args));
}

size_t ft_get_printf_base_int_flag(va_list *args)//i -> OK
{
    int nbr = va_arg(*args, int);
    char * nbr_itoa = ft_itoa(nbr);
    ft_putstr_fd(nbr_itoa, 1);
    return (ft_strlen(nbr_itoa));
    return 0;
}

size_t ft_get_printf_unsigned_int_decimal_flag(va_list *args)//u -> OK
{
    unsigned int nbr = va_arg(*args, unsigned int);
    char * nbr_itoa = ft_itoa(nbr);
    ft_putstr_fd(nbr_itoa, 1);
    return (ft_strlen(nbr_itoa));
    return 0;
}

size_t ft_get_printf_hex_unsigned_int_flag(va_list *args)//x -> OK
{
    unsigned int nbr = va_arg(*args, unsigned int);
    char * nbr_itoa = ft_itoa_base(nbr, 16);
    ft_putstr_fd(nbr_itoa, 1);
    return (ft_strlen(nbr_itoa));
    return 0;
}

size_t ft_get_printf_upper_hex_unsigned_int_flag(va_list *args)//X -> OK
{
    unsigned int nbr = va_arg(*args, unsigned int);
    char * nbr_itoa = ft_itoa_base(nbr, 16);
    ft_putstr_fd(ft_toupper(nbr_itoa), 1);
    return (ft_strlen(nbr_itoa));
    return 0;
}*/