NAME        = libftprintf.a

SRCS_PATH    = sources/

LIBFT_PATH    = libft/

LIBFT_LIB    = libft.a

HEADERS_FOLDER    = includes/

SRCS_FILES = \
	./sources/ft_flags.c \
	./sources/ft_justification.c \
	./sources/ft_parse.c \
	./sources/ft_print_char.c \
	./sources/ft_print_hexa.c \
	./sources/ft_print_idu.c \
	./sources/ft_print_percent.c \
	./sources/ft_print_pointer.c \
	./sources/ft_print_string.c \
	./sources/ft_printf.c \
	./sources/ft_protection.c \
	./sources/ft_set_list.c \
	./sources/ft_update_struct.c \

SRCS_OBJS     = ${SRCS_FILES:.c=.o}

CC         = gcc

CFLAGS         = -Wall -Wextra -Werror

RM         = rm -f

AR         = ar rcs

LIBFT_OBJS    = ${LIBFT_PATH}*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

all:		${NAME}

${NAME}:    ${SRCS_OBJS} pmake
			${AR} ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS}

pmake:
			${LIBFTMAKE}

clean:
			make -C ${LIBFT_PATH} clean
			${RM} ${SRCS_OBJS}

fclean:		clean
			${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}
			rm -rf ./sources/a.out
			rm -rf ./libft/a.out

re:			fclean all

.PHONY:		all clean fclean re
