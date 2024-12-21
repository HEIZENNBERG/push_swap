

SRC = main.c push_swap.c push_swap_utils.c  stack_utils.c ft_split.c push_instra.c swap_instra.c rotate_instra.c reverse_instra.c tiny_sort.c 

OBJ = ${SRC:.c=.o}

CC = cc

NAME = push_swap

RM = rm -f

GFLAGS = -Wall -Wextra -Werror

all : ${NAME}

%.o: %.c push_swap.h
	${CC} ${GFLAGS} -c $< -o $@ 

${NAME} : ${OBJ}
	${CC} -fsanitize=address ${OBJ} -o ${NAME}

clean : 
	${RM} ${OBJ}  

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: clean fclean all