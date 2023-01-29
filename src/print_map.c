/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:19:55 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/29 15:31:13 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	print_map(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		printf ("%s", game->map.map[y]);
		y++;
	}
	printf ("\n");
}

void	get_posicion_player(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (game->map.map[y] )
	{
		x = 0;
		while (game->map.map[y][x] != 0)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
			x++;
		}
		y++;
	}
}
