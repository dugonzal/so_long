/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/22 23:15:26 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check(t_game *game, int y, int x)
{
	return (game->map.map[y][x] == '1' || game->map.map[y][x] == '0' \
			|| game->map.map[y][x] == 'C' || game->map.map[y][x] == '\n' || \
			game->map.map[y][x] == 'E' || game->map.map[y][x] == 'P');
}

void	check_characters(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[x][y])
		{
			if (!check (game, y, x))
				errors ("hay carateres no contemplados en el mapa");
			++x;
		}
		++y;
	}
}

void	check_map(t_game *game)
{
	int		x;
	int		err;
	size_t	len;

	x = 0;
	err = 0;
	len = arr_size (game->map.map);
	while (x < game->map.width)
	{
		if (game->map.map[0][x] != '1' \
		|| game->map.map[len - 1][x] != '1')
			err++;
		x++;
	}
	x = -1;
	while (++x < game->map.height)
	{
		if (game->map.map[x][0] != '1' || \
		game->map.map[x][game->map.width - 2] != '1')
			err++;
	}
	if (err > 1)
		errors ("Map periferia != 1");
}

void	assign_caracteres_map(t_game *game)
{
	int	y;
	int	x;
	int	exit;

	y = 0;
	exit = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'C')
				game->map.count += 1;
			else if (game->map.map[y][x] == 'P')
				game->map.player += 1;
			else if (game->map.map[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (!game->map.count ||  game->map.player != 1 || \
	exit != 1)
		errors (" mapa invalido, hay mas o menos jugadores,\
		coleccionables o salidas en el mapa");
}

void	parser_map(t_game *game)
{
	check_map(game);
	assign_caracteres_map(game);
	check_characters (game);
}
