/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:22:24 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/03 23:19:07 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"
#include <mlx.h>
#include <X11/keysym.h>

int	key_hooks(int key_code, t_game *game)
{
	if (key_code == XK_Escape)
		mlx_loop_end(game->mlx);
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
		return (1);
	}
	game = init_game(map);
	mlx_hook(game->win, 17, 0, &mlx_loop_end, game->mlx);
	mlx_hook(game->win, 2, 1L << 0, &key_hooks, game);
	mlx_do_key_autorepeaton(game->mlx);
	mlx_loop_hook(game->mlx, &render_map, game);
	mlx_loop(game->mlx);
	cleanup_game(game);
	ft_putstr_fd("Total moves: ", 1);
	ft_putnbr_fd(game->movements, 1);
	ft_putendl_fd("\nLeaving Game...", 1);
	return (0);
}
