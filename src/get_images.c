/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:57:56 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/28 23:06:55 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_xpm(t_game *game)
{
	if (!game->img.player || !game->img.wall || !game->img.floor \
	|| !game->img.exit || !game->img.collects )
		errors("XPM not found");
}

static void	get_xpm(t_game *game)
{
	int x;
	int y;

	game->img.player = mlx_xpm_file_to_image(game->mlx, avatar, &(x), &(y));
	game->img.wall = mlx_xpm_file_to_image (game->mlx, walls, &(x), &(y));
	game->img.floor = mlx_xpm_file_to_image(game->mlx, floors, &(x), &(y));
	game->img.exit = mlx_xpm_file_to_image (game->mlx, exit_e, &(x), &(y));
	game->img.collects = mlx_xpm_file_to_image (game->mlx, collect, &(x), &(y));
	check_xpm(game);
}

void	get_images(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	get_xpm(game);
	while (game->map.map[y] != 0)
	{
		x = 0;
		while (game->map.map[y][x] != 0)
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.wall, (x * 32), (y * 32));
			else if (game->map.map[y][x] == '0')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.floor, (x * 32), (y * 32));
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.exit, (x * 32), (y * 32));
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.collects, (x * 32), (y * 32));
			else if (game->map.map[y][x] == 'P')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.player, (x * 32), (y * 32));
			x++;
		}
		y++;
	}
}
