/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/24 12:51:33 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
		errors ("");
}
