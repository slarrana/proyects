CHECK = checker
SWAP = push_swap
SRCS_CHECK = checker.c exec_comm.c comandos.c test.c
SRCS_SWAP = swap.c comandos.c
OBJS_CHECK = ${SRCS_CHECK:.c=.o}
OBJS_SWAP = ${SRCS_SWAP:.c=.o}
CFLAGS = -Wall -Wextra -Werror

all: ${CHECK} ${SWAP}

${SWAP}: ${OBJS_SWAP}
	make -C libft/
	gcc ${OBJS_SWAP} -o ${SWAP} -L libft -lft

${CHECK}: ${OBJS_CHECK}
	make -C libft/
	gcc ${OBJS_CHECK} -o ${CHECK} -L libft -lft

checker: ${CHECK}

push_swap: ${SWAP}

re: fclean all

clean:
	rm -f ${OBJS_CHECK} ${OBJS_SWAP}
	make clean -C libft
fclean: clean
	rm -f ${CHECK} ${SWAP}
	make fclean -C libft
