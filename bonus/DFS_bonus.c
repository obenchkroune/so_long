/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DFS_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:22:05 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/03 23:15:21 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"
#include <stdbool.h>

bool	dfs(char **map, int x, int y, char target)
{
	if (x < 0 || y < 0 || \
		x > (int)ft_strlen(map[0]) - 1 || \
		y > (int)ft_tabsize(map) - 1 || map[y][x] == '1' || \
		map[y][x] == 'V')
		return (false);
	if (map[y][x] == target)
		return (true);
	map[y][x] = 'V';
	return (dfs(map, x + 1, y, target) || dfs(map, x, y + 1, target) \
			|| dfs(map, x - 1, y, target) || dfs(map, x, y - 1, target));
}
