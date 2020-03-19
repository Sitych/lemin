.PHONY: all clean fclean re
LST = lemin.c parse.c hash.c lst_func.c check.c rretta.c
SRCS = $(addprefix src/, $(LST))
CC = gcc
NAME = lem-in
HEADER = includes
LIB =  ./libft
LIB_H = $(LIB)/includes/
FLAGS = -Wall -Wextra -Werror -I $(HEADER) -I $(LIB_H)
OBJ = $(LST:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@make -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L./$(LIB) -lft
	@echo "$(NAME) IS READY FOR NAGIB"

$(OBJ): $(SRCS)
	@gcc $(FLAGS) -c $(SRCS)

clean:
	make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	@rm -f $(NAME)

re: fclean all
