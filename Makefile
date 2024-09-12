NAME = pipex

CC = cc

FLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = ./libft-complete

LIBFT_LIB = ${LIBFT_DIR}/libftcomplete.a

LIBFT_FLAG = -lftcomplete

INCLUDES = -I ./Includes/

SOURCES = 	./Sources/main.c\
			./Sources/utils.c

OBJS = ${SOURCES:.c=.o}

all : ${NAME}

${NAME} : ${OBJS} ${LIBFT_LIB}
	${CC} ${FLAGS} ${OBJS} -L${LIBFT_DIR} -o $@ ${LIBFT_FLAG}

${LIBFT_LIB} :
	${MAKE} -C ${LIBFT_DIR}

%.o : %.c
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

clean : 
	${MAKE} clean -C ${LIBFT_DIR}
	${RM} ${OBJS}

fclean : clean
	${MAKE} fclean -C ${LIBFT_DIR}
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
