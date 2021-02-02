# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slarrana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 14:45:04 by slarrana          #+#    #+#              #
#    Updated: 2020/01/27 13:31:39 by slarrana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_substr.c ft_strtrim.c ft_strnstr.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_atoi_hex.c ft_itoa_hex.c get_next_line.c
SRCS_B	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS	= ${SRCS:.c=.o}
OBJS_B	= ${SRCS_B:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			cc ${CFLAGS} -c ${SRCS}
			ar rc ${NAME} ${OBJS}

bonus:		${OBJS_B}
			cc ${CFLAGS} -c ${SRCS_B}
			ar rc ${NAME} ${OBJS_B}

			
clean:		
			rm -f ${OBJS} ${OBJS_B}

fclean:		clean
			rm -f ${NAME}
re:			fclean all

