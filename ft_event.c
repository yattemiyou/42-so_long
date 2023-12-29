/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 06:14:10 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/29 18:24:17 by anonymous        ###   ########.fr       */
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
	ft_game_is_game_over(game);
}

static	int	key_hook(int keycode, void *param)
{
	char	c;
	t_game	*game;

	c = (char)keycode;
	game = (t_game *)param;
	if (c == K_ESC)
		ft_game_finalize(game, NULL);
	else if ((c == K_W) && game->player.i > 0)
		move_player(game, 0, -1, UP);
	else if ((c == K_S) && game->player.i < game->height - 1)
		move_player(game, 0, 1, DOWN);
	else if (c == K_A && game->player.j > 0)
		move_player(game, -1, 0, LEFT);
	else if (c == K_D && game->player.j < game->width - 1)
		move_player(game, 1, 0, RIGHT);
	return (0);
}

static int	mouse_hook(int button, int x, int y, void *param)
{
	t_game	*game;

	(void)x;
	(void)y;
	game = (t_game *)param;
	if (button == M_UP)
		key_hook('w', game);
	else if (button == M_DOWN)
		key_hook('s', game);
	else if (button == M_LEFT)
		key_hook('a', game);
	else if (button == M_RIGHT)
		key_hook('d', game);
	return (0);
}

static int	game_over(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_game_finalize(game, NULL);
	return (0);
}

void	ft_event_initialize(t_game *game)
{
	mlx_hook(game->win, 17, 0, game_over, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_mouse_hook(game->win, mouse_hook, game);
}
