/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:07:20 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/01 16:26:45 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

void	load_sprite(t_game *game, t_sprite *sprite, char *file)
{
	sprite->img = mlx_xpm_file_to_image(
			game->mlx, file, &sprite->width, &sprite->height);
}

static void	set_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

t_game	*init_game(char **map)
{
	t_game	*game;
	int		width;
	int		height;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map_size_x = ft_strlen(map[0]);
	game->map_size_y = ft_tabsize(map);
	game->movements = 0;
	width = game->map_size_x * 50;
	height = game->map_size_y * 50;
	game->map = map;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	game->collectibles_left = count_char_occurence(map, 'C');
	set_player_pos(game);
	load_sprite(game, &game->brick, "sprites/brick.xpm");
	load_sprite(game, &game->player, "sprites/player.xpm");
	load_sprite(game, &game->collectible, "sprites/shield.xpm");
	load_sprite(game, &game->door, "sprites/door.xpm");
	load_sprite(game, &game->background, "sprites/background.xpm");
	return (game);
}
