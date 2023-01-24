/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:57:56 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/24 08:58:28 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_images(t_game *game)
{
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "images/black.xpm", &game->img.width, &game->img.height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "images/portal.xpm", &game->img.width, &game->img.height);
}

int	create_map(t_game *game)
{
	int y;
	int x;

	y = 0;
	
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.floor, (game->img.width * x), (game->img.height * y ));
			else if (game->map.map[y][x] == '1')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.wall, (game->img.width * x), (game->img.height * y));
			else if (game->map.map[y][x] == 'E')
					mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.exit, (game->img.width * x), (game->img.height * y));
			x++;
		}
		y++;
	}
	return (0);
} 
