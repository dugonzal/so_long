/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/24 17:53:51 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_characters(t_game *game)
{
	int i;
	int n;
	int p;

	i = 0;
	p = 0;
	while (game->map.map[i])
	{
		n = 0;
		while (game->map.map[i][n])
		{
			if (game->map.map[i][n] == '1' || game->map.map[i][n] == '0' \
			|| game->map.map[i][n] == 'C' || game->map.map[i][n] == '\n' || \
			game->map.map[i][n] == 'E' || game->map.map[i][n] == 'P' )
			{
				if (game->map.map[i][n - 1] == 'E' || game->map.map[i][n - 1] == 'P')
					p++;
				n++;
			}
			else
				errors ("hay carateres no contemplados en el mapa");
		}
		i++;
	}
	if (p != 2)
	errors ("hay mas de un avatar o salidas en el mapa");
}


void	check_map(t_game *game)
{
	int	v;
	int	err;
	size_t len;

	v = 0;
	err = 0;
	len = arr_size (game->map.map) - 1;
	while (v < game->map.width)// anchura
	{
		if (game->map.map[0][v] != '1' || game->map.map[len][v] != '1')
			err++;
		v++;
	}
	v = 0;
	while (++v < game->map.height) // altura
	{
		if (game->map.map[v][0] != '1' || game->map.map[v][game->map.width-2] != '1')
			err++;
	}
	if (err > 1)
		errors ("Map periferia != 1");
	check_characters (game);
}
