/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:42:49 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/27 22:08:32 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line.h"
# include "libft.h"

# define PIXEL 32

typedef enum e_direction
{
	NONE = -1,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	DIRECTIONS
}	t_direction;

typedef struct s_pos
{
	int		valid;
	size_t	i;
	size_t	j;
}	t_pos;

typedef struct s_game
{
	char	**map;
	size_t	width;
	size_t	height;
	size_t	collectible;
	size_t	exit;
	t_pos	player;
	void	*mlx;
	void	*win;
	void	*empty;
	void	*dot;
	void	*wall;
	void	*power;
	void	*goal;
	void	*pacman[DIRECTIONS];
}	t_game;

void	ft_event_initialize(t_game *game);

void	ft_game_initialize(t_game *game, const char *map_file);
void	ft_game_finalize(t_game *game, char *error);

void	ft_graphic_initialize(t_game *game, const char *map_file);
void	ft_graphic_put_image(t_game *game, char c, t_pos pos, t_direction d);
void	ft_graphic_finalize(t_game *game);

void	ft_map_read(t_game *game, const char *map_file);
void	ft_map_free(char ***map);

char	**ft_util_copy_map(t_game *game);
void	ft_util_print_map(char **map);

void	ft_validation_is_valid_map(t_game *game);

#endif
