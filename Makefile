LIB_A_NAME = ft_printf.a
LIB_H_NAME = ft_printf.h
LIB_SRC = ft_printf.c \
	ft_printf_utils.c
LIB_OBJ = $(LIB_SRC:.c=.o)
# LIB_OBJ = $(patsubst %.c,obj/%.o,$(LIB_SRC))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
# # Programa ar (archiver).
# r = replace (reemplaza objetos existentes)
# c = create (crea la librería si no existe)
# s = crea el índice de símbolos para que el linker la use
CMD_AR_RCS_FLAG = ar rcs
# # Comando rm
# -f = force
CMD_RM_F_FLAG = rm -f
#
$(LIB_OBJ): $(LIB_H_NAME)# todos los .o(LIB_OBJ) dependen de ft_printf.h(LIB_H_NAME)
	@echo "Compiling printf..."
	@$(CC) $(CFLAGS) -c $(LIB_SRC)
# obj/%.o: %.c $(LIB_H_NAME)# compiling_v2
# 	@mkdir -p obj
# 	$(CC) $(CFLAGS) -c $< -o $@
# Esto es una dependencia. Indica que para construir ft_printf.a(LIB_A_NAME), primero necesito que existan los objetos .o(LIB_OBJ).
# Cuando existen los objetos, ejecutamos el programa ar (archiver) para crear una libreria estatica. Es equivalente a decir "mete estos .o dentro del archivo ft_printf.a".
$(LIB_A_NAME): $(LIB_OBJ)
	@echo "Doing ar comand"
	@$(CMD_AR_RCS_FLAG) $(LIB_A_NAME) $(LIB_OBJ)
## Make Rules
# make all
all: $(LIB_A_NAME)
# make clean
clean:
	@echo "Doing Clean ..."
	@$(CMD_RM_F_FLAG) $(LIB_OBJ)
# make fclean
fclean: clean
	@echo "Doing fclean ..."
	@$(CMD_RM_F_FLAG) $(LIB_A_NAME)
# make re
re: fclean all
#
tests: fclean
	@echo "Doing tests ..."
#
.PHONY: all clean fclean re tests