/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:31:18 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/22 17:08:55 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	errors(char *str)
{
	printf ("Error\n %s\n", str);
	exit (1);
}

int	close_window(t_game *game)
{
	mlx_destroy_window (game->mlx, game->mlx_win);
	exit(EXIT_SUCCESS);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == Q)
		close_window(game);
	return (0);
}

void	map_images(t_game *game)
{
	game->img.width = 10;
	game->img.height = 10;
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "src/test.xpm",\
	&game->img.width, &game->img.height);
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
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.floor, (game->img.width * x), (game->img.height * y));
			x++;
		}
		y++;
	}
	return (0);
} 
