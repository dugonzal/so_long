/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:57:56 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/27 13:37:04 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


static void	get_xpm(t_game *game)
{
	game->img.player = mlx_xpm_file_to_image(game->mlx, avatar, &(game->img.size.x_avatar), &(game->img.size.y_avatar));
	game->img.wall = mlx_xpm_file_to_image (game->mlx, walls, &(game->img.size.x_wall), &(game->img.size.y_wall));
	game->img.floor = mlx_xpm_file_to_image(game->mlx, floors, &(game->img.size.x_floor), &(game->img.size.y_floor));
	game->img.exit = mlx_xpm_file_to_image (game->mlx, exit_e, &(game->img.size.x_portal), &(game->img.size.y_portal));
	game->img.collects = mlx_xpm_file_to_image (game->mlx, collect, &(game->img.size.x_collect), &(game->img.size.y_collect));	
}

void	get_images(t_game *game)
{
	int y;
	int x;

	y = 0;
	get_xpm(game);
	while (game->map.map[y] != 0)
	{
		x = 0;
		while (game->map.map[y][x] != 0)
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.wall, (game->img.size.x_wall * x), (game->img.size.y_wall * y));
			else if (game->map.map[y][x] == '0')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.floor, (game->img.size.x_floor * x), (game->img.size.y_floor * y + 10));
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.exit, (game->img.size.x_portal * x), (game->img.size.y_portal * y));
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.collects, (game->img.size.x_collect * x), (game->img.size.y_collect * y));
			else if (game->map.map[y][x] == 'P')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.player, (game->img.size.x_avatar * x), (game->img.size.y_avatar * y));
			x++;
		}
		y++;
	}
}


/*
void	change_map(t_game *game)
{
	
}
*/