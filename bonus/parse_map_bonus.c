/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:22:30 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/03 23:15:38 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	get_map_height(char *file)
{
	int		fd;
	size_t	height;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

static void	fill_matrix(int fd, char ***map)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		(*map)[i] = ft_strtrim(line, "\n");
		free(line);
		if (!(*map)[i])
			break ;
		i++;
	}
}

char	**parse_map(char *file)
{
	int		fd;
	char	**map;
	size_t	height;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	height = get_map_height(file);
	if (height < 3)
	{
		ft_putendl_fd("Error\nthe selected map is invalid!", 2);
		exit(EXIT_FAILURE);
	}
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	fill_matrix(fd, &map);
	close(fd);
	return (map);
}
