/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:36:24 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/17 09:55:08 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

static void	check_characters(t_game *game, const char *map_file)
{
	int		fd;
	ssize_t	n;
	char	c;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_game_finalize(game, "地図ファイルがオープンできませんでした。");
	c = '\n';
	n = read(fd, &c, sizeof(char));
	while (n > 0)
	{
		if (c == '\n')
			game->height++;
		else if (c == '\0' || ft_strchr("01CEP", c) == NULL)
		{
			close(fd);
			ft_game_finalize(game, "地図ファイルに不正な文字が含まれています。");
		}
		n = read(fd, &c, sizeof(char));
	}
	close(fd);
	if (n < 0)
		ft_game_finalize(game, "地図ファイルの読み込み中にエラーが発生しました。");
	else if (c != '\n')
		game->height++;
}

void	ft_map_read(t_game *game, const char *map_file)
{
	int		fd;
	char	**row;
	char	*line;
	size_t	len;

	check_characters(game, map_file);
	game->map = (char **)ft_calloc(game->height + 1, sizeof(char *));
	if (game->map == NULL)
		ft_game_finalize(game, "地図データのメモリ確保に失敗しました。");
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_game_finalize(game, "地図ファイルがオープンできませんでした。");
	row = game->map;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len = ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		*row++ = line;
		line = get_next_line(fd);
	}
	close(fd);
}

void	ft_map_validate(t_game *game)
{
	ft_validation_is_rectangular(game);
	ft_validation_is_surrounded(game);
}

void	ft_map_free(t_game *game)
{
	char	**ptr;

	if (game->map == NULL)
		return ;
	ptr = game->map;
	while (*ptr)
		free(*ptr++);
	free(game->map);
	game->map = NULL;
}
