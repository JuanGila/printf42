
#include "printflib.h"
#include "libft.h"
////
size_t	ft_get_printf_char_flag(va_list *args)//c -> OK
{
	ft_putchar_fd(va_arg(*args, int), 1);
	return (1);
}

size_t	ft_get_printf_string_flag(va_list *args)//s -> OK
{
	const char * n = va_arg(*args, const char *);
	ft_putstr_fd((char *)n, 1);
	return (ft_strlen(n));//se supone que usar ft_strlen es una mala idea, ver si es asi o no.
	// si lo es entonces usamos ¿?
}
/*
size_t	ft_get_printf_pointer_flag(va_list *args)//p -> TERMINAR
{
	Una cosa interesante para investigar en este contexto es el tipo uintptr_t de <stdint.h>.
	Pregúntate:
	¿Por qué existe?
	¿Qué ventaja tiene frente a hacer cast a unsigned long?
	
	// Extraemos el puntero con va_arg.
	void *ptr = va_arg(*args, void *);
	// Necesitamos un tipo entero capaz de almacenar una dirección de memoria.
	uintptr_t ptr_unit = (uintptr_t)ptr;
	// Convertimos el entero a hexadecimal.
	char *ptr_str = ft_itoa_base(ptr_unit, 16);
	// Imprimimos el prefijo 0x.
	ft_putstr_fd("0x", 1);
	// Imprimimos los dígitos hexadecimales.
	ft_putstr_fd(ptr_str, 1);
	free(ptr);//esto es error casi seguro, no hay malloc devuelto por va_arg.
	size_t len = ft_strlen(ptr_str) + 2;
	free(ptr_str);//creo que si es correcto, revisar si itoa_base en conver_base.c hace malloc, si no hace malloc eliminamos este free.
	// Devolvemos el número de caracteres impresos.
	return (len);
}*/