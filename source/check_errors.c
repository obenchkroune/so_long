/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenchkr <obenchkr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 21:21:44 by obenchkr          #+#    #+#             */
/*   Updated: 2024/01/30 21:21:44 by obenchkr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include <libft.h>
#include <stdlib.h>

/**
*	Check for errors in the command arguments
*	1- the file must be ending with the .ber extention
*	2- the program accepts one argument
*	TODO:
*	3- check if the map is valid 
*		3.1- the map is rectengular
*		3.2- the player has a path to the exit
*		3.3- the player has a path to the collectibles
*/
void	check_errors(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("usage: ./so_long [path/to/map.ber]", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
	{
		ft_putendl_fd("invalid map format '.ber' extention expected.", 2);
		exit(EXIT_FAILURE);
	}
}
