/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:40:51 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/17 09:51:09 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validation_is_rectangular(t_game *game)
{
	size_t	i;

	if (game->height == 0)
		ft_game_finalize(game, "高さが0です。");
	game->width = ft_strlen(game->map[0]);
	if (game->width == 0)
		ft_game_finalize(game, "幅が0です。");
	i = 0;
	while (i < game->height)
	{
		if (ft_strlen(game->map[i++]) != game->width)
			ft_game_finalize(game, "長方形ではありません。");
	}
}

void	ft_validation_is_surrounded(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1')
			ft_game_finalize(game, "壁で囲まれていません。");
		if (game->map[game->height - 1][i] != '1')
			ft_game_finalize(game, "壁で囲まれていません。");
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1')
			ft_game_finalize(game, "壁で囲まれていません。");
		if (game->map[i][game->width - 1] != '1')
			ft_game_finalize(game, "壁で囲まれていません。");
		i++;
	}
}
