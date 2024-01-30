CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Iinclude -Ilibft -g -fsanitize=address
CLIBS		=	-lmlx -lXext -lX11 -Llibft -lft
NAME		=	so_long

SRC			=	$(shell find ./source -type f -name '*.c')
OBJ			=	$(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C libft all
	$(CC) $(CFLAGS) $(OBJ) $(CLIBS) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ)
