/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/31 09:34:10 by dugonzal         ###   ########.fr       */
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
			x++;
		}
		y++;
	}
}

void	check_map(t_game *game)
{
	int		yx;
	int		err;
	int		len;

	yx = 0;
	err = 0;
	len = (int)arr_size (game->map.map);
	while (yx < game->map.x)
	{
		if (game->map.map[0][yx] != '1' \
		|| game->map.map[len - 1][yx] != '1')
			err++;
		yx++;
	}
	yx = -1;
	while (++yx < game->map.y)
	{
		if (game->map.map[yx][0] != '1' || \
		game->map.map[yx][game->map.x - 2] != '1')
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
				game->player.collectibles++;
			else if (game->map.map[y][x] == 'P')
				game->map.player += 1;
			else if (game->map.map[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (!game->player.collectibles || game->map.player != 1 || exit != 1)
		errors (" Mapa no valido, mas o menos caracteres de los necesarios");
}
