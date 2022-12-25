/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/25 17:11:24 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check(t_game *game, int i, int n)
{
	return (game->map.map[i][n] == '1' || game->map.map[i][n] == '0' \
			|| game->map.map[i][n] == 'C' || game->map.map[i][n] == '\n' || \
			game->map.map[i][n] == 'E' || game->map.map[i][n] == 'P');
}

void	check_characters(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	while (game->map.map[i])
	{
		n = 0;
		while (game->map.map[i][n])
		{
			if (check (game, i, n))
				n++;
			else
				errors ("hay carateres no contemplados en el mapa");
		}
		i++;
	}
}

void	check_map(t_game *game)
{
	int		v;
	int		err;
	size_t	len;

	v = 0;
	err = 0;
	len = arr_size (game->map.map);
	while (v < game->map.width)
	{
		if (game->map.map[0][v] != '1' || game->map.map[len - 1][v] != '1')
			err++;
		v++;
	}
	v = 0;
	while (++v < game->map.height)
	{
		if (game->map.map[v][0] != '1' || \
		game->map.map[v][game->map.width - 2] != '1')
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
			else if (game->map.map[i][n] == 'P') // else if mejor que if -< if
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
