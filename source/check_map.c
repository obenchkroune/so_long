/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:21:49 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/01 16:22:55 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdbool.h>

static bool	is_rectangular(char **map)
{
	size_t	i;
	size_t	length;

	length = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != length)
			return (false);
		i++;
	}
	return (true);
}

static void	set_player_pos(char **_map, int *pos_x, int *pos_y)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = dup_matrix(_map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*pos_x = j;
				*pos_y = i;
				cleanup_matrix(map);
				return ;
			}
			j++;
		}
		i++;
	}
	cleanup_matrix(map);
}

static bool	player_can_exit(char **_map)
{
	int		pos_x;
	int		pos_y;
	char	**map;
	bool	result;

	map = dup_matrix(_map);
	set_player_pos(map, &pos_x, &pos_y);
	result = dfs(map, pos_x, pos_y, 'E');
	cleanup_matrix(map);
	return (result);
}

static bool	player_reach_collectibles(char **_map)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = dup_matrix(_map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' && !dfs(map, j, i, 'P'))
			{
				cleanup_matrix(map);
				return (false);
			}
			j++;
		}
		i++;
	}
	cleanup_matrix(map);
	return (true);
}

bool	is_valid_map(char **map)
{
	return (count_char_occurence(map, 'C') > 0 && \
			count_char_occurence(map, 'P') == 1 && \
			count_char_occurence(map, 'E') == 1 && \
			is_rectangular(map) && \
			player_can_exit(map) && \
			player_reach_collectibles(map) && \
			is_serrounded(map));
}
