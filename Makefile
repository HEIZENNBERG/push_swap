

SRC = main.c push_swap.c push_swap_utils.c stack_utils.c ft_split.c push_instra.c \
      swap_instra.c rotate_instra.c reverse_instra.c tiny_sort.c prepare_stack.c \
      fill_a.c utils.c

SRC_B = bonus_checker.c bonus_gnl.c bonus_main.c bonus_push.c bonus_push_swap_utils.c \
        bonus_reverse.c bonus_rotate.c bonus_split.c bonus_stack_utils.c bonus_swap.c \
        bonus_utils.c

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRC_B:.c=.o}

CC = cc

NAME = push_swap

NAME_B = checker

RM = rm -f

GFLAGS = -Wall -Wextra -Werror

all : ${NAME}

%.o: %.c push_swap.h onus_push_swap.h
	${CC} ${GFLAGS} -c $< -o $@ 

${NAME} : ${OBJ}
	${CC} -fsanitize=address ${OBJ} -o ${NAME}

bonus: ${OBJ_B}
	${CC} -fsanitize=address ${OBJ_B} -o ${NAME_B}

clean : 
	${RM} ${OBJ} ${OBJ_B} 

fclean : clean
	${RM} ${NAME} ${NAME_B}

re : fclean all

.PHONY: clean fclean all bonus