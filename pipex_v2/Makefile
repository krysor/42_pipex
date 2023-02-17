CFILES	= main.c ft_getallpaths.c ft_freearr.c ft_getpath.c \
			ft_noheredoc.c ft_loop.c ft_exit.c ft_fork.c
bCFILES = main_bonus.c ft_getallpaths.c ft_freearr.c ft_getpath.c \
			ft_noheredoc.c ft_loop.c ft_exit.c ft_fork.c \
				ft_heredoc_bonus.c get_next_line_bonus.c
SRCS 	= $(addprefix src/, ${CFILES})
bSRCS	= $(addprefix src/, ${bCFILES})

OBJS	= ${SRCS:.c=.o}
bOBJS	= ${bSRCS:.c=.o}

NAME	= pipex

CC		= cc
RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address

${NAME}:	${OBJS}
			${MAKE} -C libft
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} libft/libft.a

all:		${NAME}

bonus:		${bOBJS}
			@${MAKE} -C libft
			@${CC} ${CFLAGS} -o ${NAME} ${bOBJS} libft/libft.a
			@echo "make: \`pipex' is up to date."

clean:
			${RM} ${OBJS} ${bOBJS}
			$(MAKE) clean -C libft

fclean:		clean
			${RM} ${NAME}
			$(MAKE) fclean -C libft

re:			fclean all

.PHONY:		all bonus clean fclean re