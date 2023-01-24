/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 08:57:56 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/24 15:13:43 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


/*	
tengo que guaradar los tamaños de las imagenes por separado porque al tener diferentes tamaños
eso hace que al empujarlo las imagenes a pantalla haya conflicto entre tamaños de imagenes
*/
void	map_images(t_game *game)
{
	int i;
	int j;
	
	game->img.floor = mlx_xpm_file_to_image(game->mlx, black, &game->img.width, &game->img.height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, walls, &game->img.size.x_wall, &game->img.size.y_wall);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, portal, &game->img.width, &game->img.height);
	game->img.collect = mlx_xpm_file_to_image(game->mlx, coin, &(j), &(i));
	game->img.player = mlx_xpm_file_to_image (game->mlx, avatar, &(game->img.size.x_player), &(game->img.size.y_player));
}

void	create_map(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.wall, (game->img.size.x_wall * x), (game->img.size.y_wall * y));
			else if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.floor, (game->img.width * x), (game->img.height * y));
			else if (game->map.map[y][x] == 'E')
					mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.exit, (game->img.width * x), (game->img.height * y));
			else if (game->map.map[y][x] == 'C')
					mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.collect, (game->img.width * x), (game->img.height * y));
			else if (game->map.map[y][x] == 'P')
					mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.player, (game->img.size.x_player * y), (game->img.size.y_player * x));
			x++;
		}
		y++;
	}
} 
