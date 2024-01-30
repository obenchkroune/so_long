/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:21:03 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/30 21:21:12 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	ft_put_image(t_game *game, t_sprite *sprite, int x, int y)
{
	int	pos_x;
	int	pos_y;

	pos_x = x * 50;
	pos_y = y * 50;
	mlx_put_image_to_window(game->mlx, game->win, sprite->img, pos_x, pos_y);
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
	return (0);
}
