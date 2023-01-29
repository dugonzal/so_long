/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:01 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/29 15:28:25 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_game *game, char *path)
{
	init_structs (path, game);
	len_map (game);
	read_map (game);
	check_map (game);
	assign_caracteres_map(game);
	get_posicion_player(game);
}

void events_hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1, close_window, game);// con este loop o bucle podemos cerra la ventana desde la x
	mlx_hook(game->mlx_win, 2, 1, key_press, game);
}


int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		errors ("no se ha especificado un mapa");
	init_map (&game, av[1]);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map.width * 32 - 28, game.map.height * 32, "so_long");
	events_hooks (&game);
	get_images (&game);
	mlx_loop(game.mlx);
}
