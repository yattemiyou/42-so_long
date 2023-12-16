/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:33:02 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/17 08:17:40 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <unistd.h>

void	ft_game_initialize(t_game *game, const char *map_file)
{
	ft_map_read(game, map_file);
	ft_map_validate(game);
}

void	ft_game_finalize(t_game *game, char *error)
{
	ft_map_free(game);
	if (error == NULL)
		exit(0);
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(1);
}
