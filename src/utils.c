/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:31:18 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/25 10:46:21 by dugonzal         ###   ########.fr       */
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
    while (game->map.map)
    {
        if (game->map.map)
            free (game->map.map);
        game->map.map++;
    }
}

int	close_window(t_game *game)
{
	mlx_destroy_window (game->mlx, game->mlx_win);
	//antes de salir del programa vamos a liberar la memoria reservada para el mapa
	clean_map (game);
	exit(EXIT_SUCCESS);
}

