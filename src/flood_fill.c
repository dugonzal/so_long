/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:08:39 by dugonzal          #+#    #+#             */
/*   Updated: 2023/02/03 18:28:21 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	flood_fill(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	if (game->map.map[y][x] == 'C')
	{
		game->player.collected++;
		game->map.map[y][x] = '0';
	}
	if (game->map.map[y][x] == 'E')
		game->player.check_exit = 1;
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
	if (game->player.check_exit != 1)
		errors ("no se recoge la salida");
	if (game->player.collected == game->player.collectibles)
	{
		clean_map (game);
		read_map (game);
		return ;
	}
	else
		errors ("no se han recogido todas las monedas");
}
