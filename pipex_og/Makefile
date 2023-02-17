SRCS	= main.c ft_getallpaths.c ft_freearr.c ft_getpath.c get_next_line.c

OBJS	= ${SRCS:.c=.o}

NAME	= pipex

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

${NAME}:	${OBJS}
			${MAKE} -C libft
			${MAKE} bonus -C libft
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a

all:		${NAME}

bonus:		${OBJS}
			${MAKE} -C libft
			${MAKE} bonus -C libft
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a

clean:
			${RM} ${OBJS}
			$(MAKE) clean -C libft

fclean:		clean
			${RM} ${NAME}
			$(MAKE) fclean -C libft

re:			fclean all

.PHONY:		all bonus clean fclean re