/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:36:24 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/03 15:42:45 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

static int	add_line(t_game *game, char *line)
{
	char	**new_map;
	char	*ptr;

	ptr = ft_strchr(line, '\n');
	if (ptr == NULL)
		return (FALSE);
	new_map = (char **)ft_calloc(game->height + 1, sizeof(char *));
	if (new_map == NULL)
		return (FALSE);
	ft_memcpy(new_map, game->map, game->height * sizeof(char *));
	new_map[game->height] = line;
	*ptr = '\0';
	free(game->map);
	game->map = new_map;
	game->height += 1;
	return (TRUE);
}

int	ft_map_read(t_game *game, const char *map_file)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (FALSE);
	game->status = TRUE;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (game->status == TRUE)
			game->status = add_line(game, line);
		if (game->status == FALSE)
			free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (game->status == FALSE)
		ft_map_free(game);
	return (game->status);
}

void	ft_map_free(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
		free(game->map[i++]);
	free(game->map);
	game->map = NULL;
}

int	ft_map_validate(t_game *game)
{
	if (ft_validation_is_rectangular(game) == FALSE)
	{
		ft_strlcpy(game->message, "地図が長方形ではありません。", sizeof(game->message));
		return (FALSE);
	}
	return (TRUE);
}