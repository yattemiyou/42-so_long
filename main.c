/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:39:08 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/03 14:06:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	t_game	game;

	if (argc != 2)
		return (1);
	if (ft_game_initialize(&game, argv[1]) == FALSE)
		return (1);
	ft_game_finalize(&game);
	return (0);
}
