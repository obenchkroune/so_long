/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:21:57 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/30 21:21:58 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
#include <stdlib.h>

void	cleanup_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix && matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	cleanup_game(t_game *game)
{
	cleanup_matrix(game->map);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_image(game->mlx, game->brick.img);
	mlx_destroy_image(game->mlx, game->background.img);
	mlx_destroy_image(game->mlx, game->collectible.img);
	mlx_destroy_image(game->mlx, game->door.img);
	mlx_destroy_image(game->mlx, game->player.img);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}
