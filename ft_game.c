/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:33:02 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/03 15:18:46 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_game_initialize(t_game *game, const char *map_file)
{
	ft_bzero(game, sizeof(t_game));
	if (ft_map_read(game, map_file) == FALSE)
		return (FALSE);
	if (ft_map_validate(game) == FALSE)
	{
		ft_putendl_fd(game->message, 1);
		return (FALSE);
	}
	return (TRUE);
}

void	ft_game_finalize(t_game *game)
{
	ft_map_free(game);
}
