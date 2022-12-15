/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:16:47 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/14 22:41:51 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(char *file_d)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		return ;
	map->file_d = file_d;
}

void	read_map(t_map	*map)
{
/*	int fd;
	char *line;

	fd = open()*/
}
