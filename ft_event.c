/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 06:14:10 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/27 22:11:42 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, int x, int y, t_direction d)
{
	static size_t	number_of_movements = 0;
	t_pos			pos;

	pos.i = game->player.i;
	pos.j = game->player.j;
	if (game->map[pos.i + y][pos.j + x] == '1')
		return ;
	ft_graphic_put_image(game, game->map[pos.i][pos.j], pos, NONE);
	game->player.i = pos.i + y;
	game->player.j = pos.j + x;
	if (game->map[game->player.i][game->player.j] == '0')
		game->map[game->player.i][game->player.j] = 'X';
	else if (game->map[game->player.i][game->player.j] == 'C')
	{
		game->map[game->player.i][game->player.j] = 'X';
		game->collectible--;
	}
	ft_graphic_put_image(game, 'P', game->player, d);
	ft_putnbr_fd(++number_of_movements, 1);
	ft_putendl_fd("", 1);
}

static	int	key_hook(int keycode, void *param)
{
	char	c;
	t_game	*game;

	c = (char)keycode;
	game = (t_game *)param;
	if (c == 0x1b)
		ft_game_finalize(game, NULL);
	else if ((c == 'w' || c == 'q') && game->player.i > 0)
		move_player(game, 0, -1, UP);
	else if ((c == 'a' || c == 'z') && game->player.i < game->height - 1)
		move_player(game, 0, 1, DOWN);
	else if (c == 's' && game->player.j > 0)
		move_player(game, -1, 0, LEFT);
	else if (c == 'd' && game->player.j < game->width - 1)
		move_player(game, 1, 0, RIGHT);
	return (0);
}

void	ft_event_initialize(t_game *game)
{
	mlx_key_hook(game->win, key_hook, game);
}