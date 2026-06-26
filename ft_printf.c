/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgilaber <jgilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:09:22 by jgilaber          #+#    #+#             */
/*   Updated: 2026/06/24 21:53:47 by jgilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printflib.h"

static const t_printf_flag_handler	printf_flags_handler[] = {
	{'c', ft_get_printf_char_flag},
	{'s', ft_get_printf_string_flag},
	{'d', ft_get_printf_int_decimal_flag},
	{'i', ft_get_printf_base_int_flag},
	{'u', ft_get_printf_unsigned_int_decimal_flag},
	{'x', ft_get_printf_lower_hex_unsigned_int_flag},
	{'X', ft_get_printf_upper_hex_unsigned_int_flag},
	{'p', ft_get_printf_pointer_flag},
	//{'%', ft_get_printf_percent_flag},
	{0, NULL}
};

int	printf_flag_dispatcher(const char *format, va_list *args)//ft_printf_args_parser
{
	int	i;

	i = 0;
	while (printf_flags_handler[i].specifier  != *format)
		i++;
	if (printf_flags_handler[i].specifier == *format)
		return (printf_flags_handler[i].func(args));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	int		printf_length;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	printf_length = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '\0')
			return (-1);
		if (*format == '%')
		{
			format++;
			printf_length += printf_flag_dispatcher(format, &args);
		}
		else
		{
			write(1, format, 1);
			printf_length++;
		}
		format++;
	}
	va_end(args);
	return (printf_length);
}


void	ft_check_printf_res(char *test_id, int printf_res, int ft_printf_res)
{
	/*if (ft_printf_res == printf_res) printf("%s: OK\n", test_id);
    else printf("%s:KO\n", test_id);*/
	char *test_result = (printf_res == ft_printf_res) ? "OK" : "KO";
	printf("%s.{%S}\n", test_id, test_result);
    printf("printf: %d -> ft_printf: %d\n\n", printf_res, ft_printf_res);
}
////
void ft_printf_c_flag_tests(void) {
	int printf_res = 0;
	int ft_printf_res = 0;

	ft_printf_res = ft_printf("Test1: %c\n", '!');
	printf_res = printf("Test1: %c\n", '!');
	ft_check_printf_res("Test1(common char)", printf_res, ft_printf_res);
	ft_printf_res = ft_printf("Test1: %c\n", 'a');
	printf_res = printf("Test1: %c\n", 'a');
	ft_check_printf_res("Test1(common char)2", printf_res, ft_printf_res);
	ft_printf_res = ft_printf("Test1: %c\n", ' ');
	printf_res = printf("Test1: %c\n", ' ');
	ft_check_printf_res("Test1(common char)3", printf_res, ft_printf_res);
	ft_printf_res = ft_printf("Test1: %c\n", 'Z');
	printf_res = printf("Test1: %c\n", 'Z');
	ft_check_printf_res("Test1(common char)4", printf_res, ft_printf_res);
	ft_printf_res = ft_printf("Test1: %c\n", '0');
	printf_res = printf("Test1: %c\n", '0');
	ft_check_printf_res("Test1(common char)5", printf_res, ft_printf_res);
	ft_printf_res = ft_printf("Test1: %c\n", '\n');
	printf_res = printf("Test1: %c\n", '\n');
	ft_check_printf_res("Test1(common char)6", printf_res, ft_printf_res);
	ft_printf_res = ft_printf("Test1: %c\n", '\t');
	printf_res = printf("Test1: %c\n", '\t');
	ft_check_printf_res("Test1(common char)7", printf_res, ft_printf_res);
	ft_printf_res = ft_printf("Test1: %c\n", '~');
	printf_res = printf("Test1: %c\n", '~');
	ft_check_printf_res("Test1(common char)8", printf_res, ft_printf_res);
}
void ft_printf_s_flag_tests(void) {
	int printf_res = 0;
	int ft_printf_res = 0;

	// Se comprueba que se muestra un string normal
	ft_printf_res = ft_printf("Hello %s\n", "world");
	printf_res = printf("Hello %s\n", "world");
	ft_check_printf_res("Test6(normal-string)", printf_res, ft_printf_res);//test -> OK

	// Se comprueba que se muestra un string vacio
	ft_printf_res = ft_printf("Hello%s\n", "");
	printf_res = printf("Hello%s\n", "");
	ft_check_printf_res("Test7(empty-string)", printf_res, ft_printf_res);

	// Se comprueba que se muestra un string ausente(nulo)
	ft_printf_res = ft_printf("Hello %s\n", NULL);
	printf_res = printf("Hello %s\n", (char *)NULL);// esto es -> NULL directamente sin casteo
	ft_check_printf_res("Test8(null-string)", printf_res, ft_printf_res);

	// Se comprueba que se muestran varios strings consecutivos(frase).
	ft_printf_res = ft_printf("Hello %s %s %s %s\n", "world", "to all", "of you.", "");
	printf_res = printf("Hello %s %s %s %s\n", "world", "to all", "of you.", "");
	ft_check_printf_res("Test9(concatenated/consecutive-strings)", printf_res, ft_printf_res);

	// Se comprueba que se muestran varios strings consecutivos ausentes.
	ft_printf_res = ft_printf("Hello %s%s %s%s %s%s\n", "world", NULL, "to all", NULL, NULL, "of you.");
	printf_res = printf("Hello %s%s %s%s %s%s\n", "world", (char *)NULL, "to all", (char *)NULL, (char *)NULL, "of you.");
	ft_check_printf_res("Test10(concatenated/consecutive-strings)", printf_res, ft_printf_res);
}
void ft_printf_p_flag_tests(void) {
    int printf_res = 0;
	int ft_printf_res = 0;

    int x = 42;
    int y = 84;
    char c = 'A';
    char *str = "Hola";
    int array[5] = {1, 2, 3, 4, 5};
    void *heap = malloc(sizeof(int));

    // Puntero a variable local
    ft_printf_res = ft_printf("Test1: %p\n", &x);
    printf_res = printf("Test1: %p\n", &x);
    ft_check_printf_res("Pointer to int", printf_res, ft_printf_res);

    // Puntero a char
    ft_printf_res = ft_printf("Test2: %p\n", &c);
    printf_res = printf("Test2: %p\n", &c);
    ft_check_printf_res("pointer to char", printf_res, ft_printf_res);

    // Puntero a string
    ft_printf_res = ft_printf("Test3: %p\n", str);
    printf_res = printf("Test3: %p\n", str);
    ft_check_printf_res("pointer to string", printf_res, ft_printf_res);

    // Dirección del array
    ft_printf_res = ft_printf("Test4: %p\n", array);
    printf_res = printf("Test4: %p\n", array);
    ft_check_printf_res("pointer to array", printf_res, ft_printf_res);

    // Dirección de un elemento del array
    ft_printf_res = ft_printf("Test5: %p\n", &array[3]);
    printf_res = printf("Test5: %p\n", &array[3]);
    ft_check_printf_res("pointer to array element", printf_res, ft_printf_res);

    // Puntero obtenido con malloc
    ft_printf_res = ft_printf("Test6: %p\n", heap);
    printf_res = printf("Test6: %p\n", heap);
    ft_check_printf_res("malloc pointer", printf_res, ft_printf_res);

    // Puntero nulo
    ft_printf_res = ft_printf("Test7.1: %p\n", (void *)0);
    printf_res = printf("Test7.1: %p\n", (void *)0);
    ft_check_printf_res("NULL pointer((void *)0)", printf_res, ft_printf_res);
    // Si #define NULL 0, enotnces posible UB(Undefined Behavior/Comportamiento indefinido).
    ft_printf_res = ft_printf("Test7.2: %p\n", NULL);
    printf_res = printf("Test7.2: %p\n", NULL);
    ft_check_printf_res("NULL pointer(NULL)", printf_res, ft_printf_res);

    // Dos punteros en la misma llamada
    ft_printf_res = ft_printf("Test8: %p %p\n", &x, &y);
    printf_res = printf("Test8: %p %p\n", &x, &y);
    ft_check_printf_res("two different pointers", printf_res, ft_printf_res);

    // Mismo puntero repetido
    ft_printf_res = ft_printf("Test9: %p %p %p\n", &x, &x, &x);
    printf_res = printf("Test9: %p %p %p\n", &x, &x, &x);
    ft_check_printf_res("same pointer repeated", printf_res, ft_printf_res);

    // Puntero a puntero
    int *pointer = &y;
    ft_printf_res = ft_printf("Test10: %p\n", &pointer);
    printf_res = printf("Test10: %p\n", &pointer);
    ft_check_printf_res("pointer to pointer", printf_res, ft_printf_res);

    // Puntero Con Limites Positivos
    ft_printf_res = ft_printf("Test11: %p\n", (void *)LONG_MAX);
    printf_res = printf("Test11: %p\n", (void *)LONG_MAX);
    ft_check_printf_res("pointer with positive limits", printf_res, ft_printf_res);

    // Puntero Con Limites Negativos
    ft_printf_res = ft_printf("Test12: %p\n", (void *)LONG_MIN);
    printf_res = printf("Test12: %p\n", (void *)LONG_MIN);
    ft_check_printf_res("pointer with negative limits", printf_res, ft_printf_res);
    // FREE
    free(heap);
}
void ft_printf_d_flag_tests(void) {
	int printf_res = 0;
	int ft_printf_res = 0;

	ft_printf_res = ft_printf("INT_MAX -> %i\n", INT_MAX-1);
	printf_res = printf("INT_MAX -> %i\n", INT_MAX-1);
	ft_check_printf_res("Test21(base-int)", printf_res, ft_printf_res);

	ft_printf_res = ft_printf("INT_MIN -> %i\n", INT_MIN);
	printf_res = printf("INT_MIN -> %i\n", INT_MIN);
	ft_check_printf_res("Test5(base-int-negative)", printf_res, ft_printf_res);
}
void ft_printf_i_flag_tests(void) {
	int printf_res = 0;
	int ft_printf_res = 0;

	ft_printf_res = ft_printf("INT_MAX -> %i\n", INT_MAX-1);
	printf_res = printf("INT_MAX -> %i\n", INT_MAX-1);
	ft_check_printf_res("Test21(base-int)", printf_res, ft_printf_res);

	ft_printf_res = ft_printf("INT_MIN -> %i\n", INT_MIN);
	printf_res = printf("INT_MIN -> %i\n", INT_MIN);
	ft_check_printf_res("Test5(base-int-negative)", printf_res, ft_printf_res);
}
void ft_printf_u_flag_tests(void) {
	int printf_res = 0;
	int ft_printf_res = 0;

	ft_printf_res = ft_printf("INT_MAX -> %i\n", UINT_MAX);
	printf_res = printf("INT_MAX -> %i\n", UINT_MAX);
	ft_check_printf_res("Test21(base-int)", printf_res, ft_printf_res);
}
void ft_printf_mutiple_flag_tests(void) {
	int printf_res = 0;
	int ft_printf_res = 0;
	// Test9 -> %%
	ft_printf_res = ft_printf("Hello %%\n");
	printf_res = printf("Hello %%\n");// Hello %
	ft_check_printf_res("Test9(%%-operator)", printf_res, ft_printf_res);//test -> OK

	// Test10 -> Combinacion de varios flags separados por palabras
	ft_printf_res = ft_printf("Bienvenidos %c 42. %s\n", 'a', "Mi login es jgilaber.");
	printf_res = printf("Bienvenidos %c 42. %s\n", 'a', "Mi login es jgilaber.");
	ft_check_printf_res("Test10(various-separated-flags)", printf_res, ft_printf_res);//test -> OK

	// Test11 -> Combinacion de varios flags seguidos
	ft_printf_res = ft_printf("Bienvenidos %c %s. Mi login es jgilaber.\n", 'a', "42");
	printf_res = printf("Bienvenidos %c %s. Mi login es jgilaber.\n", 'a', "42");
	ft_check_printf_res("Test11(various-consecutive-flags)", printf_res, ft_printf_res);//test -> OK

	// Test12 -> Combinacion de comportamientos indefinidos/raros
	ft_printf_res = ft_printf("Bienvenidos %%%c %%%%s. Mi login es jgilaber.\n", 'a', "42");
	printf_res = printf("Bienvenidos %%%c %%%s. Mi login es jgilaber.\n", 'a', "42");
	ft_check_printf_res("Test12(various-undefined-behavior)", printf_res, ft_printf_res);//test -> OK

	// Test13 -> Combinacion de comportamientos indefinidos/raros
	ft_printf_res = ft_printf("%");
	printf_res = printf("%");
	ft_check_printf_res("Test13(%%sin flag)", printf_res, ft_printf_res);
}

////
int	main(void)
{
	ft_printf_c_flag_tests();
	ft_printf_s_flag_tests();
	//ft_printf_p_flag_tests();
	ft_printf_d_flag_tests();
	ft_printf_i_flag_tests();
	ft_printf_u_flag_tests();
	//ft_printf_x_flag_tests();
	//ft_printf_X_flag_tests();
	//ft_printf_mutiple_flag_tests();
	return (0);
}