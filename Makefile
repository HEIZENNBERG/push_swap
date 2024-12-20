

SRC = push_swap_utils.c stack_utils.c ft_split.c instructions.c

OBJ = ${SRC:.c=.o}

LIBC = ar rcs

CC = cc

NAME = libftpushswap.a

RM = rm -f

GFLAGS = -Wall -Wextra -Werror

all : ${NAME}

%.o: %.c push_swap.h
	${CC} ${GFLAGS} -c $< -o $@ 

${NAME} : ${OBJ}
	${LIBC} ${NAME} ${OBJ}

clean : 
	${RM} ${OBJ}  

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: clean fclean all