PUSH_FILES = pipex.c pipex_utils.c main.c
OBJS = ${PUSH_FILES:.c=.o}
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
NAME = pipex
LIBFTA = ./libft/libft.a
LIBFTD = ./libft

BONUS = pipex_bonus
BONUS_FILES = pipex_bonus.c pipex_utils.c
OBJSB = ${BONUS_FILES:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${LIBFTA}
			${CC} ${CFLAGS} $(OBJS) ${LIBFTA} -o ${NAME}

${LIBFTA}:	${LIBFTD}
		make -C ${LIBFTD}

bonus: ${OBJSB}
			${RM} ${OBJS} ${NAME}
			@make OBJS="${OBJSB}" all

#			${RM} ${NAME}

#${NAME}:		${OBJSB} ${LIBFTA}
#				${CC} ${CFLAGS} ${OBJS} ${OBJSB} ${LIBFTA} -o ${NAME}

clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME} ${CHECKER}

re:			fclean ${NAME}

.phony: all clean fclean re bonus
