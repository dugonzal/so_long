/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:31:18 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/30 22:29:49 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_posicion_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x] != 0)
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
			x++;
		}
		y++;
	}
}

void	errors(char *str)
{
	printf (RED"Error\n %s\n"RESET, str);
	exit (1);
}

void	clean_map(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		if (game->map.map[y])
			free (game->map.map[y]);
		y++;
	}
}

int	close_window(t_game *game)
{
	mlx_destroy_window (game->mlx, game->mlx_win);
	mlx_destroy_image (game->mlx, game->img.exit);
	mlx_destroy_image (game->mlx, game->img.collects);
	mlx_destroy_image (game->mlx, game->img.floor);
	mlx_destroy_image (game->mlx, game->img.player);
	clean_map (game);
	exit(EXIT_SUCCESS);
}

void	win(t_game *game)
{
	ft_printf(GREEN"\n\
						██████████████████████████████████████████████████████████████████\n\
						██                                                              ██\n\
						██  ███  ███  ██████  ██    ██     ██      ██ ██ ██    ██   ██  ██\n\
						██   ██  ██  ██    ██ ██    ██     ██      ██ ██ ███   ██   ██  ██\n\
						██    ████   █      █ ██    ██     ██  ██  ██ ██ ██ ██ ██   ██  ██\n\
						██     ██    ██    ██ ██    ██     ██ ████ ██ ██ ██  ████       ██\n\
						██     ██     ██████    ████        ███  ███  ██ ██   ███   ██  ██\n\
						██                                                              ██\n\
						██████████████████████████████████████████████████████████████████\n\
	\n"RESET);
	close_window(game);
}
