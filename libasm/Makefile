# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slarrana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 14:14:01 by slarrana          #+#    #+#              #
#    Updated: 2021/02/10 18:22:57 by slarrana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
SRCS = ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
OBJS = ${SRCS:.s=.o}

CFLAGS = -Wall -Wextra

%.o	: %.s
	nasm -f macho64 $< -o $@

all: ${NAME}

${NAME}: ${OBJS}
			ar rcs ${NAME} ${OBJS}
re: fclean all

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
