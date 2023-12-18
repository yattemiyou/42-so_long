/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:05:47 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/19 06:55:14 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <unistd.h>

char	**ft_util_copy_map(t_game *game)
{
	char	**new_map;
	char	**src;
	char	**dest;
	char	*s;

	new_map = (char **)ft_calloc(game->height + 1, sizeof(char *));
	if (new_map == NULL)
		ft_game_finalize(game, "地図データのメモリ確保に失敗しました。");
	src = game->map;
	dest = new_map;
	while (*src)
	{
		s = ft_strdup(*src++);
		if (s == NULL)
		{
			ft_map_free(&new_map);
			ft_game_finalize(game, "地図データのメモリ確保に失敗しました。");
		}
		*dest++ = s;
	}
	return (new_map);
}

void	ft_util_print_map(char **map)
{
	ft_putendl_fd("----------------------------", STDOUT_FILENO);
	while (*map)
		ft_putendl_fd(*map++, STDOUT_FILENO);
	ft_putendl_fd("----------------------------", STDOUT_FILENO);
}
