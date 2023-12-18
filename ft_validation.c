/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:40:51 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/19 07:04:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_rectangular(t_game *game)
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

static void	is_surrounded(t_game *game)
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

static int	is_reachable(t_game *game, size_t i, size_t j)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if ((i >= game->height) || (j >= game->width))
		return (FALSE);
	if (game->map[i][j] == 'X')
		return (FALSE);
	if (game->map[i][j] == '1')
		return (FALSE);
	if (game->map[i][j] == 'C')
		game->collectible--;
	if (game->map[i][j] == 'E')
		return (TRUE);
	game->map[i][j] = 'X';
	up = is_reachable(game, i - 1, j);
	down = is_reachable(game, i + 1, j);
	left = is_reachable(game, i, j - 1);
	right = is_reachable(game, i, j + 1);
	return (up || down || left || right);
}

void	ft_validation_is_valid_map(t_game *game)
{
	char	**map;
	size_t	collectible;
	int		result[2];

	is_rectangular(game);
	is_surrounded(game);
	if (game->collectible == 0)
		ft_game_finalize(game, "経由地が存在しません。");
	if (game->exit.valid == FALSE)
		ft_game_finalize(game, "出口が存在しません。");
	if (game->player.valid == FALSE)
		ft_game_finalize(game, "プレイヤーが存在しません。");
	map = ft_util_copy_map(game);
	collectible = game->collectible;
	result[0] = (game->collectible == 0);
	result[1] = is_reachable(game, game->player.i, game->player.j);
	ft_map_free(&game->map);
	game->map = map;
	game->collectible = collectible;
	if (result[0] == FALSE)
		ft_game_finalize(game, "すべての経由地に到達できません。");
	if (result[1] == FALSE)
		ft_game_finalize(game, "ゴールに到達できません。");
}
