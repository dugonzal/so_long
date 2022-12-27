/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:31:18 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/27 15:02:50 by ciclo            ###   ########.fr       */
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

int	create_map(t_game *game)
{
	int i;
	int n;

	i = 0;
	while (game->map.map[i])
	{
		n = 0;
		while (game->map.map[i][n])
		{
			if (game->map.map[i][n] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, n * 30, i * 50);
			n++;
		}
		i++;
	}
	return (0);
}
