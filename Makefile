# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/01 16:54:52 by obenchkr          #+#    #+#              #
#    Updated: 2024/02/03 23:16:38 by obenchkr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -Iinclude -Ilibft
CLIBS		=	-lmlx -lXext -lX11 -Llibft -lft
NAME		=	so_long
BONUS_NAME	=	so_long_bonus

SRC			=	$(wildcard ./source/*.c)
OBJ			=	$(SRC:.c=.o)

BONUS_SRC	=	$(wildcard ./bonus/*.c)
BONUS_OBJ	=	$(BONUS_SRC:.c=.o)

all: $(NAME)

bonus: $(BONUS_NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C libft all
	$(CC) $(CFLAGS) $(OBJ) $(CLIBS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	make -C libft all
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(CLIBS) -o $(BONUS_NAME)

clean:
	make -C libft clean
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus

.SECONDARY: $(OBJ)
