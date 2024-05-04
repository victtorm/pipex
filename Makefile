PUSH_FILES = pipex.c pipex_utils.c

OBJS = ${PUSH_FILES:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
NAME = pipex
LIBFTA = ./libft/libft.a
LIBFTD = ./libft

# BONUS = 
# OBJSB = ${BONUS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${LIBFTA}
			${CC} ${CFLAGS} $(OBJS) ${LIBFTA} -o ${NAME}

${LIBFTA}:	${LIBFTD}
		make -C ${LIBFTD}

bonus: ${CHECKER} 

${CHECKER}:		${OBJSB}
				${CC} ${CFLAGS} ${OBJS} ${OBJSB} ${LIBFTA} -o ${CHECKER}

clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME} ${CHECKER}

re:			fclean ${NAME}

.phony: all clean fclean re bonus
