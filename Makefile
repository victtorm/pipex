PUSH_FILES = pipex.c pipex_utils.c main.c
OBJS = ${PUSH_FILES:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
NAME = pipex
LIBFTA = ./libft/libft.a
LIBFTD = ./libft

BONUS = pipex_bonus
BONUS_FILES = pipex_bonus.c pipex_bonus_utils.c
OBJSB = ${BONUS_FILES:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${LIBFTA}
			${CC} ${CFLAGS} $(OBJS) ${LIBFTA} -o ${NAME}

${LIBFTA}:	${LIBFTD}
		make -C ${LIBFTD}

bonus: ${BONUS}

${BONUS}:	${OBJSB} ${LIBFTA}
			${CC} ${CFLAGS} $(OBJSB) ${LIBFTA} -o ${BONUS}



clean:
			${RM} ${OBJS} ${OBJSB}
			make clean -s -C ${LIBFTD}

fclean:		clean
			${RM} ${NAME} ${BONUS} ${LIBFTA}

re:			fclean ${NAME}

.phony: all clean fclean re bonus
