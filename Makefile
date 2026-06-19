PRINTF_A_NAME = libftprintf.a
PRINTF_LIB_DIR = ./
PRINTF_LIB_FILES = \
	ft_printf.c \
	ft_printf_utils.c
PRINTF_LIB_SRCS = $(addprefix $(PRINTF_LIB_DIR), $(PRINTF_LIB_FILES))
PRINTF_LIB_OBJS = $(PRINTF_LIB_SRCS:.c=.o)
LIBFT_LIB_DIR = libft/
LIBFT_LIB_FILES = \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strncmp.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_strdup.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_bzero.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_calloc.c \
	ft_memmove.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c
LIBFT_LIB_SRCS = $(addprefix $(LIBFT_LIB_DIR), $(LIBFT_LIB_FILES))
LIBFT_LIB_OBJS = $(LIBFT_LIB_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
CINCLUDES = -I ./includes
# # Programa ar (archiver).
# r = replace (reemplaza objetos existentes)
# c = create (crea la librería si no existe)
# s = crea el índice de símbolos para que el linker la use
CMD_AR_RCS_FLAG = ar rcs
# # Comando rm
# -f = force
CMD_RM_F_FLAG = rm -f
#
%.o: %.c
	@echo "Compiling $< ..."
	@$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@
# Esto es una dependencia. Indica que para construir ft_printf.a(PRINTF_A_NAME), primero necesito que existan los objetos .o(PRINTF_LIB_OBJS).
# Cuando existen los objetos, ejecutamos el programa ar (archiver) para crear una libreria estatica. Es equivalente a decir "mete estos .o dentro del archivo ft_printf.a".
$(PRINTF_A_NAME): $(PRINTF_LIB_OBJS) $(LIBFT_LIB_OBJS)
	@echo "Doing ar command"
	@$(CMD_AR_RCS_FLAG) $(PRINTF_A_NAME) $(PRINTF_LIB_OBJS) $(LIBFT_LIB_OBJS)
# # Make Rules
# make all
all: $(PRINTF_A_NAME)
# make clean
clean:
	@echo "Doing Clean ..."
	@$(CMD_RM_F_FLAG) $(PRINTF_LIB_OBJS) $(LIBFT_LIB_OBJS)
# make fclean
fclean: clean
	@echo "Doing fclean ..."
	@$(CMD_RM_F_FLAG) $(PRINTF_A_NAME)
# make re
re: fclean all
#
.PHONY: all clean fclean re