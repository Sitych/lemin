CC = gcc
NAME = lem-in
HEADER = includes
LIB =  ./libft
LIB_H = $(LIB)/includes/
FLAGS = -Wall -Wextra -Werror -I $(HEADER) -I $(LIB_H)
SOURCES =	lemin.c parse.c hash.c room.c check.c bfs.c link.c \
			queue.c edge.c way.c bellman_ford.c bhandari.c printer.c \
			counter.c validation.c solution.c print.c\

DIR_S = src
DIR_O = obj
SRC = $(addprefix $(DIR_S)/,$(SOURCES))
OBJ = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@make -C $(LIB)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) -L./$(LIB) -lft
	@echo "$(NAME) IS READY FOR NAGIB"

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $< -g

clean:
	make clean -C libft
	@rm -f $(OBJ)
	@rm -rf $(DIR_O)

fclean: clean
	make fclean -C libft
	@rm -f $(NAME)

re: fclean all
