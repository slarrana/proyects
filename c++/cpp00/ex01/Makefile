NAME = listin
SRCS = listin.cpp
OBJS = ${SRCS:.cpp=.o}
CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	clang++ ${CLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
