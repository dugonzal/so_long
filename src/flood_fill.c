/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:08:39 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/31 10:09:30 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	flood_fill(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'C')
	{
		game->player.collected++;
		game->map.map[y][x] = '0';
	}
	if (game->map.map[y][x] == '0' || game->map.map[y][x] == 'P')
	{
		game->map.map[y][x] = 'F';
		flood_fill (game, x + 1, y);
		flood_fill (game, x - 1, y);
		flood_fill (game, x, y + 1);
		flood_fill (game, x, y - 1);
	}
}

void	check_flood_file(t_game *game)
{
	flood_fill (game, game->player.x, game->player.y);
	if (game->player.collected == game->player.collectibles)
	{
		read_map (game);
		return ;
	}
	else
		errors ("no se han recogido todas las monedas");
}
