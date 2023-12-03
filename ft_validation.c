/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:40:51 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/03 15:41:10 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validation_is_rectangular(t_game *game)
{
	int	i;

	if (game->height == 0)
		return (FALSE);
	game->width = ft_strlen(game->map[0]);
	if (game->width == 0)
		return (FALSE);
	i = 0;
	while (i < game->height)
	{
		if (ft_strlen(game->map[i++]) != (size_t)game->width)
			return (FALSE);
	}
	return (TRUE);
}
