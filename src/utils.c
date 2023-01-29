/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:31:18 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/29 15:43:05 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	errors(char *str)
{
	printf ("Error\n %s\n", str);
	exit (1);
}

void clean_map(t_game *game)
{
    int y;

    y = 0;
    while (game->map.map[y])
    {
        if (game->map.map[y])
            free (game->map.map[y]);
        y++;
    }
}

//antes de salir del programa vamos a liberar la memoria reservada para el mapa
int	close_window(t_game *game)
{
	mlx_destroy_window (game->mlx, game->mlx_win);
    mlx_destroy_image (game->mlx, game->img.exit);
    mlx_destroy_image (game->mlx, game->img.collects);
    mlx_destroy_image (game->mlx, game->img.floor);
    mlx_destroy_image (game->mlx ,game->img.player);
    clean_map (game);
	exit(EXIT_SUCCESS);
}

void    win(t_game *game)
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
