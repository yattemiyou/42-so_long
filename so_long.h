/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:42:49 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/17 09:52:46 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"

typedef struct s_game
{
	char	**map;
	size_t	width;
	size_t	height;
	size_t	player;
	size_t	exit;
	size_t	collectible;
}	t_game;

void	ft_game_initialize(t_game *game, const char *map_file);
void	ft_game_finalize(t_game *game, char *error);

void	ft_map_read(t_game *game, const char *map_file);
void	ft_map_validate(t_game *game);
void	ft_map_free(t_game *game);

void	ft_validation_is_rectangular(t_game *game);
void	ft_validation_is_surrounded(t_game *game);

#endif
