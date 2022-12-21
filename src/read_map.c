/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:16:47 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/21 15:20:41 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(char *file_d, 	t_game *game)
{
	game->map.file_d = file_d;
	game->map.height = 0;
	game->map.width = 0;
	game->map.map = 0;
	game->player.collectibles = 0;
	game->player.x = 0;
	game->player.scape = 0;
	game->player.collectibles = 0;
}

void	read_game(t_game *game)
{
	ft_printf ("%s", game->map.file_d);
}
