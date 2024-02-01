# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 16:54:52 by obenchkr          #+#    #+#              #
#    Updated: 2024/02/01 21:22:05 by obenchkr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Iinclude -Ilibft
CLIBS		=	-lmlx -lXext -lX11 -Llibft -lft
NAME		=	so_long

SRC_DIR		=	./source
OBJ_DIR		=	./object

FILES		=	check_errors.c check_map.c check_serrounded_map.c cleanup.c DFS.c get_next_line.c handle_movements.c init_game.c main.c parse_map.c render_map.c utils.c

SRC			=	$(addprefix $(SRC_DIR)/, $(FILES))
OBJ			=	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))


all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
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
