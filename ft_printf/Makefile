NAME	= libftprintf.a
SRCS	= ft_printf.c ft_putunbr_fd.c ft_itoa_hexmin.c ft_itoa_hexmayus.c ft_printdir.c ft_uitoa.c flags.c strings.c numbers.c adress.c chars.c adress2.c basic.c
OBJS	= ${SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

all:	${NAME}

${NAME}:	${OBJS}
		make -C libft/
		cp libft/libft.a ./${NAME}
		cc ${CFLAGS} -c ${SRCS}
		ar rc ${NAME} ${OBJS}

clean:
		rm -f ${OBJS}
		make -C libft/ clean

fclean:	clean
	rm -f ${NAME}
	make -C libft/ fclean

re:	fclean all
