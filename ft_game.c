/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:33:02 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/03 14:05:31 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_initialize(t_game *game, const char *map_file)
{
	ft_bzero(game, sizeof(t_game));
	return (ft_map_read(game, map_file));
}

void	ft_game_finalize(t_game *game)
{
	ft_map_free(game);
}
