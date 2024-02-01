/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:22:24 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/01 16:47:08 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <mlx.h>
#include <X11/keysym.h>
#include <stdlib.h>

int	key_hooks(int key_code, t_game *game)
{
	if (key_code == XK_Escape)
	{
		cleanup_game(game);
		exit(EXIT_SUCCESS);
	}
	handle_movements(key_code, game);
	return (0);
}

int	main(int ac, char **av)
{
	char	**map;
	t_game	*game;

	check_errors(ac, av);
	map = parse_map(av[1]);
	if (!map || !is_valid_map(map))
	{
		cleanup_matrix(map);
		ft_putendl_fd("Error\nthe selected map is invalid!", 2);
		return (1);
	}
	game = init_game(map);
	mlx_hook(game->win, 17, 0, &mlx_loop_end, game->mlx);
	mlx_hook(game->win, 2, 1L << 0, &key_hooks, game);
	mlx_do_key_autorepeaton(game->mlx);
	mlx_loop_hook(game->mlx, &render_map, game);
	mlx_loop(game->mlx);
	cleanup_game(game);
	return (0);
}
