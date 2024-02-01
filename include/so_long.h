/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:28:47 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/01 16:23:26 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}	t_sprite;

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			player_x;
	int			player_y;
	int			map_size_x;
	int			map_size_y;
	int			collectibles_left;
	int			movements;
	t_sprite	brick;
	t_sprite	player;
	t_sprite	collectible;
	t_sprite	door;
	t_sprite	background;
}	t_game;

size_t	ft_tabsize(char **tab);
char	*get_next_line(int fd);
void	check_errors(int ac, char **av);
bool	is_valid_map(char **map);
bool	dfs(char **map, int x, int y, char target);
char	**parse_map(char *file);
void	cleanup_matrix(char **matrix);
char	**dup_matrix(char **matrix);
t_game	*init_game(char **map);
int		render_map(t_game *game);
void	cleanup_game(t_game *game);
int		count_char_occurence(char **map, char c);
void	handle_movements(int key_code, t_game *game);
bool	is_serrounded(char **map);

#endif
