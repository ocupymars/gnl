NAME        = libftprintf.a

SRCS_PATH    = srcs/

LIBFT_PATH    = libft/

LIBFT_LIB    = libft.a

HEADERS_FOLDER    = includes/

SRCS_FILES    = \
	./srcs/ft_flags.c \
	./srcs/ft_ifs.c \
	./srcs/ft_justify.c \
	./srcs/ft_parse_conversions.c \
	./srcs/ft_parse_specifiers.c \
	./srcs/ft_printf_char.c \
	./srcs/ft_printf_hexa.c \
	./srcs/ft_printf.c \
	./srcs/ft_printf_id.c \
	./srcs/ft_printf_percent.c \
	./srcs/ft_printf_pointer.c \
	./srcs/ft_printf_string.c \
	./srcs/ft_printf_uint.c \
	./srcs/ft_set_list.c \
	./srcs/ft_update_struct.c \

SRCS_OBJS     = ${SRCS_FILES:.c=.o}

CC         = gcc

CFLAGS         = -Wall -Wextra -Werror

RM         = rm -f

AR         = ar crs

LIBFT_OBJS    = ${LIBFT_PATH}*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

all:				${NAME}

${NAME}:    ${SRCS_OBJS} pmake
			${AR} ${NAME} ${SRCS_OBJS} ${LIBFT_OBJS}

pmake:
			${LIBFTMAKE}

clean:
			make -C ${LIBFT_PATH} clean
			${RM} ${SRCS_OBJS}

fclean: 	clean
			${RM} ${NAME} ${LIBFT_PATH}${LIBFT_LIB}

re:         fclean all

.PHONY:        all clean fclean re
