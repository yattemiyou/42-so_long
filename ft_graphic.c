/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 06:46:52 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/29 09:11:19 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	to_image(t_game *game, void **ptr, char *path)
{
	int	s;

	*ptr = mlx_xpm_file_to_image(game->mlx, path, &s, &s);
	if (*ptr == NULL)
		ft_game_finalize(game, "イメージファイルの読み込みに失敗しました。");
}

static void	display_characters(t_game *game)
{
	t_pos	pos;

	game->map[game->player.i][game->player.j] = 'X';
	pos.i = 0;
	while (pos.i < game->height)
	{
		pos.j = 0;
		while (pos.j < game->width)
		{
			ft_graphic_put_image(game, game->map[pos.i][pos.j], pos, NONE);
			pos.j++;
		}
		pos.i++;
	}
	ft_graphic_put_image(game, 'P', game->player, RIGHT);
}

void	ft_graphic_initialize(t_game *game, const char *map_file)
{
	int	x;
	int	y;

	game->mlx = mlx_init();
	if (game->mlx == NULL)
		ft_game_finalize(game, "MLXライブラリの初期化に失敗しました。");
	x = game->width * PIXEL;
	y = game->height * PIXEL;
	game->win = mlx_new_window(game->mlx, x, y, (char *)map_file);
	to_image(game, &game->empty, "./images/empty.xpm");
	to_image(game, &game->dot, "./images/dot.xpm");
	to_image(game, &game->wall, "./images/wall.xpm");
	to_image(game, &game->power, "./images/power.xpm");
	to_image(game, &game->goal, "./images/exit.xpm");
	to_image(game, &game->pacman[UP], "./images/up.xpm");
	to_image(game, &game->pacman[DOWN], "./images/down.xpm");
	to_image(game, &game->pacman[LEFT], "./images/left.xpm");
	to_image(game, &game->pacman[RIGHT], "./images/right.xpm");
	display_characters(game);
}

void	ft_graphic_put_image(t_game *game, char c, t_pos pos, t_direction d)
{
	void	*img;
	int		x;
	int		y;

	if (c == '0')
		img = game->dot;
	if (c == 'X')
		img = game->empty;
	else if (c == '1')
		img = game->wall;
	else if (c == 'C')
		img = game->power;
	else if (c == 'E')
		img = game->goal;
	else if (c == 'P')
		img = game->pacman[d];
	x = pos.j * PIXEL;
	y = pos.i * PIXEL;
	mlx_put_image_to_window(game->mlx, game->win, img, x, y);
}

void	ft_graphic_finalize(t_game *game)
{
	if (game->mlx != NULL)
		mlx_destroy_window(game->mlx, game->win);
	if (game->empty != NULL)
		mlx_destroy_image(game->mlx, game->empty);
	if (game->dot != NULL)
		mlx_destroy_image(game->mlx, game->dot);
	if (game->wall != NULL)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->power != NULL)
		mlx_destroy_image(game->mlx, game->power);
	if (game->goal != NULL)
		mlx_destroy_image(game->mlx, game->goal);
	if (game->pacman[UP] != NULL)
		mlx_destroy_image(game->mlx, game->pacman[UP]);
	if (game->pacman[DOWN] != NULL)
		mlx_destroy_image(game->mlx, game->pacman[DOWN]);
	if (game->pacman[LEFT] != NULL)
		mlx_destroy_image(game->mlx, game->pacman[LEFT]);
	if (game->pacman[RIGHT] != NULL)
		mlx_destroy_image(game->mlx, game->pacman[RIGHT]);
}
