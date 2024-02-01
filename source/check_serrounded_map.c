/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_serrounded_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:19:08 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/01 16:38:19 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdbool.h>

bool	is_serrounded(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || !map[i + 1]))
			{
				if (map[i][j] != '1')
					return (false);
			}
			else
			{
				if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
