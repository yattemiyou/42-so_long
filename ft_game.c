/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:33:02 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/24 14:58:30 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <unistd.h>

#define EXT ".ber"

void	ft_game_initialize(t_game *game, const char *map_file)
{
	const char	*ptr;

	if (ft_strlen(map_file) <= ft_strlen(EXT))
		ft_game_finalize(game, "ファイル名が不正です。");
	ptr = map_file + (ft_strlen(map_file) - ft_strlen(EXT));
	if (ft_strncmp(ptr, EXT, ft_strlen(EXT)) != 0)
		ft_game_finalize(game, "ファイル名が不正です。");
	ft_map_read(game, map_file);
	ft_validation_is_valid_map(game);
	ft_graphic_initialize(game, map_file);
	ft_event_initialize(game);
}

void	ft_game_finalize(t_game *game, char *error)
{
	ft_map_free(&game->map);
	ft_graphic_finalize(game);
	if (error == NULL)
		exit(0);
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(1);
}
