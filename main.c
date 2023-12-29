/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:39:08 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/29 19:21:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (argc != 2)
		ft_game_finalize(&game, "起動引数が不正です。");
	ft_game_initialize(&game, argv[1]);
	mlx_loop(game.mlx);
	ft_game_finalize(&game, NULL);
}

// #include <libc.h>
// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q so_long");
// }
