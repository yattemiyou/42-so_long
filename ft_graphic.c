/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 06:46:52 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/24 13:22:09 by anonymous        ###   ########.fr       */
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

static void	put_image(t_game *game, void *ptr, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, ptr, j * PIXEL, i * PIXEL);
}

static void	display_images(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '0')
				put_image(game, game->empty, i, j);
			else if (game->map[i][j] == '1')
				put_image(game, game->wall, i, j);
			else if (game->map[i][j] == 'C')
				put_image(game, game->power, i, j);
			else if (game->map[i][j] == 'E')
				put_image(game, game->goal, i, j);
			else if (game->map[i][j] == 'P')
				game->map[i][j] = '0';
			j++;
		}
		i++;
	}
	put_image(game, game->pacman[UP], game->player.i, game->player.j);
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
	to_image(game, &game->empty, "./images/floor.xpm");
	to_image(game, &game->wall, "./images/tree.xpm");
	to_image(game, &game->power, "./images/potion.xpm");
	to_image(game, &game->goal, "./images/portal.xpm");
	to_image(game, &game->pacman[UP], "./images/D1.xpm");
	display_images(game);
}

void	ft_graphic_finalize(t_game *game)
{
	if (game->empty != NULL)
		mlx_destroy_image(game->mlx, game->empty);
	if (game->mlx != NULL)
		mlx_destroy_window(game->mlx, game->win);
}
