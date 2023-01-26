/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:57:56 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/26 22:09:01 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	get_images(t_game *game)
{
	game->img.wall = mlx_xpm_file_to_image (game->mlx, walls, &(game->img.size.x_wall), &(game->img.size.y_wall));

	int y;
	int x;

	y = 0;
	while (game->map.map[y] != 0)
	{
		x = 0;
		while (game->map.map[y][x] != 0)
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.wall, (game->img.size.x_wall * x), (game->img.size.y_wall * y));
			x++;
		}
		y++;
	}
}
