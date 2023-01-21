/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/21 21:39:38 by ciclo            ###   ########.fr       */
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
	x = 0;
	while (++x < game->map.height)
	{
		if (game->map.map[x][0] != '1' || \
		game->map.map[x][game->map.width - 2] != '1')
			err++;
	}
	if (err > 1)
		errors ("Map periferia != 1");
}

void	check_multi(t_game *game)
{
	int	i;
	int	n;
	int	err;

	i = 0;
	err = 0;
	while (game->map.map[i])
	{
		n = 0;
		while (game->map.map[i][n])
		{
			if (game->map.map[i][n] == 'C')
				game->map.count += 1;
			else if (game->map.map[i][n] == 'P')
				game->map.player += 1;
			else if (game->map.map[i][n] == 'E')
				err++;
			n++;
		}
		i++;
	}
	if (!game->map.count || !game->map.player || game->map.player != 1 || \
	err != 1 || !err)
		errors (" mapa invalido, hay mas o menos jugadores,\
		coleccionables o salidas en el mapa");
}

void	parser_map(t_game *game)
{
	check_map(game);
	check_multi (game);
	check_characters (game);
}
