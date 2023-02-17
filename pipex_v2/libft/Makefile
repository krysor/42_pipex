# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaczoro <kkaczoro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 15:04:19 by kkaczoro          #+#    #+#              #
#    Updated: 2023/01/18 11:14:51 by kkaczoro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_strlen.c ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c \
			ft_memchr.c ft_memcpy.c ft_memmove.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

${NAME}:	${OBJS}
			ar r ${NAME} ${OBJS}			

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re