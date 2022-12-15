/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:16:47 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/15 23:08:42 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_game	*init_map(char *file_d)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	if (!game)
		return ;
	game->map.file_d = file_d;
	return (game);
}

void	read_map(t_map	*map)
{
/*	int fd;
	char *line;

	fd = open()*/
}
