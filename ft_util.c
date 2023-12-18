/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:05:47 by anonymous         #+#    #+#             */
/*   Updated: 2023/12/18 21:15:10 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <unistd.h>

void	ft_util_print_map(char **map)
{
	ft_putendl_fd("----------------------------", STDOUT_FILENO);
	while (*map)
		ft_putendl_fd(*map++, STDOUT_FILENO);
	ft_putendl_fd("----------------------------", STDOUT_FILENO);
}
