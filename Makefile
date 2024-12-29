

SRC = main.c push_swap.c push_swap_utils.c stack_utils.c ft_split.c push_instra.c \
      swap_instra.c rotate_instra.c reverse_instra.c tiny_sort.c prepare_stack.c \
      fill_a.c utils.c

SRC_B = checker_bonus.c gnl_bonus.c main_bonus.c push_bonus.c push_swap_utils_bonus.c \
        reverse_bonus.c rotate_bonus.c split_bonus.c stack_utils_bonus.c swap_bonus.c \
        utils_bonus.c

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRC_B:.c=.o}

CC = cc

NAME = push_swap

NAME_B = checker

RM = rm -f

GFLAGS = -Wall -Wextra -Werror

all : ${NAME}

%.o: %.c push_swap.h 
	${CC} ${GFLAGS} -c $< -o $@ 

%bonus.o: %bonus.c push_swap_bonus.h 
	${CC} ${GFLAGS} -c $< -o $@ 

${NAME} : ${OBJ}
	${CC} ${OBJ} -o ${NAME}

bonus: ${OBJ_B}
	${CC} ${OBJ_B} -o ${NAME_B}

clean : 
	${RM} ${OBJ} ${OBJ_B} 

fclean : clean
	${RM} ${NAME} ${NAME_B}

re : fclean all

.PHONY: clean fclean all bonus