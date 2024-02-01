/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:52:48 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/01 21:18:37 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <X11/keysym.h>
#include <mlx.h>
#include <unistd.h>

void	print_matrix(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			write(1, map[i] + j, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_move_to(t_game *game, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->player_x;
	pos_y = game->player_y;
	if (x < 0 || y < 0 || x > game->map_size_x || y > game->map_size_y || \
		game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
		game->collectibles_left--;
	game->movements++;
	ft_putstr_fd("\rMoves: ", 1);
	ft_putnbr_fd(game->movements, 1);
	if (game->map[y][x] == 'E')
	{
		if (game->collectibles_left > 0)
			return ;
		else
		{
			ft_putendl_fd("\nYou Won!", 1);
			mlx_loop_end(game->mlx);
		}
	}
	game->map[pos_y][pos_x] = '0';
	game->map[y][x] = 'P';
	game->player_x = x;
	game->player_y = y;
}

void	handle_movements(int key_code, t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	if (key_code == XK_w || key_code == XK_Up)
		ft_move_to(game, x, y - 1);
	else if (key_code == XK_s || key_code == XK_Down)
		ft_move_to(game, x, y + 1);
	else if (key_code == XK_d || key_code == XK_Right)
		ft_move_to(game, x + 1, y);
	else if (key_code == XK_a || key_code == XK_Left)
		ft_move_to(game, x - 1, y);
}
