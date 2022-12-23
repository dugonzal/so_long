/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/24 00:21:15 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(t_game *game)
{
	int	v;
	int	err;

	v = 0;
	err = 0;
	while (game->map.width--)
	{
		if (game->map.map[0][v] != '1' || \
		game->map.map[arr_size (game->map.map) - 1][v] != '1')
			err++;
		v++;
	}
	v = 0;
	int len = arr_size (game->map.map)-1;
	while (--len)
	{
		if (game->map.map[v][0] != '1' || game->map.map[v][ft_strlen(game->map.map[0])-3])
			err++;
		v++;
		printf ("%c", game->map.map[v][ft_strlen(game->map.map[0])-2]);
	}
	printf ("[%d]", err);
	if (err > 1)
		errors ("");
}
