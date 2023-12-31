/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:42:49 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/29 19:08:27 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "get_next_line.h"
# include "libft.h"

# define MAX_WIDTH 50
# define MAX_HEIGHT 25
# define PIXEL 32

# ifdef __linux__
#  define K_ESC 0x1b
#  define K_W 0x77
#  define K_S 0x73
#  define K_A 0x61
#  define K_D 0x64
#  define M_UP 4
#  define M_DOWN 5
#  define M_LEFT 1
#  define M_RIGHT 3
# else
#  define K_ESC 0x35
#  define K_W 0x0d
#  define K_S 0x01
#  define K_A 0x00
#  define K_D 0x02
#  define M_UP 5
#  define M_DOWN 4
#  define M_LEFT 1
#  define M_RIGHT 2
# endif

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
void	ft_game_is_game_over(t_game *game);
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
