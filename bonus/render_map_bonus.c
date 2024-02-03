/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:21:03 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/03 23:14:45 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <mlx.h>
#include <libft.h>

void	ft_put_image(t_game *game, t_sprite *sprite, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = x * 50;
	pos_y = y * 50;
	mlx_put_image_to_window(game->mlx, game->win, sprite->img, pos_x, pos_y);
}

static void	display_moves(t_game *game)
{
	char	*moves;
	char	*str;

	moves = ft_itoa(game->movements);
	str = ft_strjoin("Moves: ", moves);
	mlx_string_put(game->mlx, game->win, 30, 30, 0x00ffffff, str);
	free(moves);
	free(str);
}

int	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '0')
				ft_put_image(game, &game->background, j, i);
			else if (game->map[i][j] == '1')
				ft_put_image(game, &game->brick, j, i);
			else if (game->map[i][j] == 'P')
				ft_put_image(game, &game->player, j, i);
			else if (game->map[i][j] == 'C')
				ft_put_image(game, &game->collectible, j, i);
			else if (game->map[i][j] == 'E')
				ft_put_image(game, &game->door, j, i);
			j++;
		}
		i++;
	}
	display_moves(game);
	return (0);
}
