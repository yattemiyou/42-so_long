/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:36:24 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/18 06:05:16 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "so_long.h"

static void	set_pos(t_pos *pos, size_t i, size_t j)
{
	pos->valid = TRUE;
	pos->i = i;
	pos->j = j;
}

static void	set_components(t_game *game, char c)
{
	if (c == '\n')
	{
		game->width = 0;
		game->height++;
		return ;
	}
	if (c == 'C')
		game->collectible++;
	else if (c == 'E')
	{
		if (game->exit.valid)
			ft_game_finalize(game, "出口が複数存在します。");
		else
			set_pos(&game->exit, game->height, game->width);
	}
	else if (c == 'P')
	{
		if (game->player.valid)
			ft_game_finalize(game, "プレイヤーが複数存在します。");
		else
			set_pos(&game->player, game->height, game->width);
	}
	game->width++;
}

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
		if (c == '\0' || ft_strchr("01CEP\n", c) == NULL)
		{
			close(fd);
			ft_game_finalize(game, "地図ファイルに不正な文字が含まれています。");
		}
		set_components(game, c);
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
