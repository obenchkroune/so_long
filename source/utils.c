/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:22:38 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/30 21:22:39 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include <stdlib.h>

size_t	ft_tabsize(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

char	**dup_matrix(char **matrix)
{
	char	**result;
	size_t	buf_size;
	size_t	i;

	buf_size = ft_tabsize(matrix);
	result = malloc(sizeof(char *) * (buf_size + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < buf_size)
	{
		result[i] = ft_strdup(matrix[i]);
		i++;
	}
	result[i] = NULL;
	return (result);
}

int	count_char_occurence(char **map, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
