/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:21:44 by obenchkr          #+#    #+#             */
/*   Updated: 2024/02/01 16:46:55 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <libft.h>
#include <stdlib.h>

void	check_errors(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("usage: ./so_long [path/to/map.ber]", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
	{
		ft_putendl_fd("Error\ninvalid map format '.ber' extention expected.", 2);
		exit(EXIT_FAILURE);
	}
}
