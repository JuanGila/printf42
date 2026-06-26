////
#include "libft.h"
#include "printflib.h"
////
//%lu
//%llu


size_t ft_get_printf_lu_flag(va_list *args)//u -> OK
{
    unsigned long nbr = va_arg(*args, unsigned long);
    char * nbr_itoa = ft_itoa(nbr);
    ft_putstr_fd(nbr_itoa, 1);
    return (ft_strlen(nbr_itoa));
    return (0);
}

size_t ft_get_printf_llu_flag(va_list *args)//u -> OK
{
    unsigned long long nbr = va_arg(*args, unsigned long long);
    char * nbr_itoa = ft_itoa(nbr);
    ft_putstr_fd(nbr_itoa, 1);
    return (ft_strlen(nbr_itoa));
    return (0);
}