/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:19:08 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/03 23:04:55 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdbool.h>

static bool	check_row_walls(char *s)
{
	while (*s)
	{
		if (*s != '1')
		{
			ft_putendl_fd("Error\nThe map is not serrounded by walls.", 2);
			return (false);
		}
		s++;
	}
	return (true);
}

bool	is_serrounded(char **map)
{
	int	i;

	i = 1;
	while (map[i + 1])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
		{
			ft_putendl_fd("Error\nThe map is not serrounded by walls.", 2);
			return (false);
		}
		i++;
	}
	return (check_row_walls(map[0]) && check_row_walls(map[i]));
}

bool	check_valid_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P' && \
				map[i][j] != 'E' && map[i][j] != 'C')
			{
				ft_putendl_fd("Error\nThe map contains invalid characters.", 2);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_characters_count(char **map)
{
	if (count_char_occurence(map, 'C') == 0)
	{
		ft_putendl_fd("The map should contain at least one collectible C.", 2);
		return (false);
	}
	if (count_char_occurence(map, 'P') != 1)
	{
		ft_putendl_fd("The map should contain one starting position P.", 2);
		return (false);
	}
	if (count_char_occurence(map, 'E') != 1)
	{
		ft_putendl_fd("The map should contain one exit E.", 2);
		return (false);
	}
	return (true);
}
