// 42 Header
#include "ft_printf.h"
#include "libft.h"
/*
%c	Carácter                        char
%s	Cadena de caracteres (string)	char *
%p	Dirección de memoria (puntero)	void *
%d	Entero decimal con signo        int
%i	Entero con signo                int
%u	Entero decimal sin signo        unsigned int
%x	Entero hexadecimal (minúsculas)	unsigned int
%X	Entero hexadecimal (mayúsculas)	unsigned int
OTROS MUY USADOS(POSIBLE BONUS)
%f      Flotante    float / double
%e      Notación científica
%g      Formato compacto para flotantes
%ld     long long int
%lld	long long int
%zu     size_t
%%      Imprime el carácter %(ya que este tiene que ser escapado al igual que la back-slash)

char letra = 'A';
char nombre[] = "Juan";
int numero = -42;
unsigned int edad = 25;
int x = 10;

printf("%c\n", letra);      // A
printf("%s\n", nombre);     // Juan
printf("%p\n", (void *)&x); // dirección de memoria
printf("%d\n", numero);     // -42
printf("%i\n", numero);     // -42
printf("%u\n", edad);       // 25
printf("%x\n", 255);        // ff
printf("%X\n", 255);        // FF

printf("%x\n", 48879); // beef
printf("%X\n", 48879); // BEEF
printf("%#x\n", 48879); // 0xbeef
printf("%#X\n", 48879); // 0XBEEF

int a = 5;
printf("%p\n", (void *)&a);
salida tipica -> 0x7ffeefbff5ac


va_list
    Antes de usar las macros, se necesita una variable de tipo -> va_list args;
    Esta variable actúa como un "cursor" que recorrerá los argumentos variables.
va_start
    Inicializa el recorrido de los argumentos variables -> va_start(args, ultimo_parametro_fijo);
    Ejemplo:
        void ejemplo(char *fmt, ...)
        {
            va_list args;
            va_start(args, fmt);
        }
        Aquí fmt es el último parámetro fijo antes de '...'
va_arg
    Obtiene el siguiente argumento de la lista -> tipo(int) valor(a) = va_arg(args, tipo);
    Ejemplo:
        int n = va_arg(args, int);
        Cada llamada avanza automáticamente al siguiente argumento.
        printf("%d %d %d\n", 10, 20, 30);
    Si recorres:
        va_arg(args, int); // 10
        va_arg(args, int); // 20
        va_arg(args, int); // 30
va_end
    Finaliza el uso de la lista -> va_end(args);
    Debe llamarse siempre cuando termines.
        va_start(args, fmt);
        // usar args
        va_end(args);
va_copy
    Copia una lista de argumentos. Es útil cuando necesitas recorrer los argumentos dos veces ->
        va_list copia;
        va_copy(copia, args);
    Ejemplo:
        va_list args;
        va_list backup;
        va_start(args, fmt);
        va_copy(backup, args);
        // usar args(los que sean)
        // backup sigue apuntando al mismo lugar inicial
        va_end(backup);
        va_end(args);
    Sin va_copy, copiar simplemente con -> backup = args; // NO portable -> puede dar problemas dependiendo de la implementación.

int sum(int n, ...) {
    va_list args;
    int total = 0;
    va_start(args, n);
    for (int i = 0; i < n; i++)
        total += va_arg(args, int);
    va_end(args);
    return total;
}
Uso: sum(3, 10, 20, 30); -> resultado: 60


Qué pasa con las promociones de tipos
Otro concepto importante de funciones variádicas: los argumentos adicionales sufren promociones por defecto antes de llegar a la función.
    char y short se promueven a int.
    float se promueve a double.
Por eso, si alguien hace: printf("%c", 'A');
internamente debes leer ese argumento como int y no como char. Lo mismo para float → leer como double.


Por qué printf necesita la cadena de formato
    La firma no contiene los tipos de los argumentos variables. Entonces, ¿cómo sabe printf qué leer? No lo sabe por la firma; lo sabe por la cadena de formato.

Ejemplo conceptual: El parser de fmt decide el orden y los tipos ->
Especificador   Tipo esperado por va_arg
    %d          int
    %s          char * (o const char * según tu diseño)
    %f          double (por la promoción de float)

Si el formato dice %d pero el llamador pasó un double, el comportamiento es indefinido. La función y el llamador deben estar de acuerdo.


Puedes pensar en va_list como un cursor opaco sobre una secuencia de argumentos ya colocados por la ABI/plataforma.
va_start posiciona el cursor justo después del último parámetro fijo;
va_arg lee “el siguiente elemento” del tipo que tú le indiques y avanza;
va_copy duplica la posición del cursor;
va_end libera/normaliza cualquier estado interno asociado.
El compilador no verifica que el tipo que pides con va_arg coincida con lo que realmente se pasó:
    esa coherencia la impone el contrato de la cadena de formato.
*/
size_t ft_get_printf_char_flag(va_list *args)//c -> TERMINAR
{
    char chr = va_arg(*args, int);
    // Promociones antes de que lleguen valores a ft_printf(*, ...): se supone que char promociona a int y tiene que ser tratado como int(preguntar).
    //char chr = va_arg(*args, int); | int chr = va_arg(*args, char);
    ft_putchar_fd(chr, 1);
    return (1);
}

size_t ft_get_printf_string_flag(va_list *args)//s -> OK
{
    const char * n = va_arg(*args, const char *);
    ft_putstr_fd((char *)n, 1);
    return (ft_strlen(n));
}

size_t ft_get_printf_pointer_flag(va_list *args)//p -> TERMINAR
{
    /*
    void *ptr = 0x1234abcd;
          ↓
    imprime: "0x1234abcd"

    Pistas para que lo implementes tú:
        Devuelves el número de caracteres impresos.
    Una cosa interesante para investigar en este contexto es el tipo uintptr_t de <stdint.h>. Pregúntate:
        ¿Por qué existe?
        ¿Qué ventaja tiene frente a hacer cast a unsigned long?

    También te recomiendo probar en tu máquina:
        int x = 42;
        printf("%p\n", &x);
        y comparar el resultado con -> printf("%lx\n", (unsigned long)&x);
    Eso te dará una pista bastante clara de cómo suele implementarse %p internamente.

    Por cierto, en el proyecto de 42 suele ser buena idea comprobar cómo se comporta el printf real con -> printf("%p\n", NULL);
        porque el tratamiento de punteros nulos es uno de los detalles donde más dudas aparecen al implementar %p.
    */
   // Extraemos el puntero con va_arg.
    void *ptr = va_arg(*args, void *);
    // Necesitamos un tipo entero capaz de almacenar una dirección de memoria.
    uintptr_t ptr_unit = (uintptr_t)ptr;
    // Convertimos el entero a hexadecimal.
    char *ptr_str = ft_itoa_base(ptr_unit, 16);//char *ptr_str = ft_itoa_base((unsigned long)ptr, 16);
    // Imprimimos el prefijo 0x.
    ft_putstr_fd("0x", 1);
    // Imprimimos los dígitos hexadecimales.
    ft_putstr_fd(ptr_str, 1);
    free(ptr);
    size_t len = ft_strlen(ptr_str) + 2;
    free(ptr_str);//creo que si es correcto, revisar si itoa_base en conver_base.c hace malloc, si no hace malloc eliminamos este free.
    // Devolvemos el número de caracteres impresos.
    return (len);
}

size_t ft_printf_args_parser(const char *format, va_list *args)//parece OK
{
    if (*format == '%') {
        write(1, "%", 1);
        return (1);
    }
    else if (*format == 'c') return (ft_get_printf_char_flag(args));
    else if (*format == 's') return (ft_get_printf_string_flag(args));
    //else if (*format == 'p') return (ft_get_printf_pointer_flag(args));
    else if (*format == 'd') return (ft_get_printf_int_decimal_flag(args));
    else if (*format == 'i') return (ft_get_printf_base_int_flag(args));
    else if (*format == 'u') return (ft_get_printf_unsigned_int_decimal_flag(args));
    //else if (*format == 'x') return (ft_get_printf_hex_unsigned_int_flag(args));
    //else if (*format == 'X') return (ft_get_printf_upper_hex_unsigned_int_flag(args));
    return (0);//caso final de comportamiento indefinido(si es indefinido seria 0, si es un error seria -1(REVISAR ESTO CON CUIDADO))
}

int ft_printf(char const *format, ...)//parece que ok parcial
{
    va_list args;
    //va_list backup;//creamos la lista de backup. Si no vas a recorrer los argumentos dos veces, se puede eliminar la lista, su copy y el end.
    int printf_length;

    va_start(args, format);
    //va_copy(backup, args);//copiamos la lista de argumentos ya inicializada al backup.
    if (!format) return (-1);
    printf_length = 0;
    while (*format) {
        if (*format == '%' && *(format + 1) == '\0')
            return (-1);
        if (*format == '%') {
            format++;
            printf_length += ft_printf_args_parser(format, &args);
        } else {
            write(1, format, 1);
            printf_length++;
        }
        format++;
    }
    va_end(args);//Finalizamos el uso de la lista
    //va_end(backup);//Finalizamos el uso de la lista de backup
    return (printf_length);
}

void ft_check_printf_res(char *test_id, int printf_res, int ft_printf_res)
{
    if (ft_printf_res == printf_res) printf("%s: OK\n", test_id);
    else printf("%s:KO\n", test_id);
    printf("printf: %d -> ft_printf: %d\n\n", printf_res, ft_printf_res);
}

int main(void) {
    int ft_printf_res = 0;
    int printf_res = 0;
    ////** */
    //// BASE-INT TESTS
    
    // Test5 -> %i
    ft_printf_res = ft_printf("INT_MAX -> %i\n", INT_MAX-1);
    printf_res = printf("INT_MAX -> %i\n", INT_MAX-1);
    ft_check_printf_res("Test21(base-int)", printf_res, ft_printf_res);

    ft_printf_res = ft_printf("INT_MIN -> %i\n", INT_MIN);
    printf_res = printf("INT_MIN -> %i\n", INT_MIN);
    ft_check_printf_res("Test5(base-int-negative)", printf_res, ft_printf_res);
    
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
    //ft_printf_res = ft_printf("%");
    //printf_res = printf("%");
    //ft_check_printf_res("Test13(%%sin flag)", printf_res, ft_printf_res);
    return (0);
    /*
    TESTS DE UINT:
    - 1 uint positivo
    - 1 uint 0
    - varios uints consecutivos
    - varios uints separados por espacios por ejemplo
    - varios uints negativos consecutivos
    - varios uints negativos separados por espacios por ejemplo
    */
   // NOTA: S e intentara lanzar los tests de todas las flags posibles. Pero si se hace torturette/hades en consola y despues el flag 's' pues hacer solo los tests correspondientes a la flag 's'.
}