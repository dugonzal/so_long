/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:01 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/27 14:14:53 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


/* si hago itero una variable de la estrcura con -- o cambio su valor
	en el flujo del programa su valor se ve alterado en la ejecucion del programa
*/
/*
static int	create_map(t_game *game)
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
				{mlx_put_image_to_window(game, avatar i, n);;
			n++;
		}
		i++;
	}
	return (0);
}
*/
void	funcions(t_game *game, char *path)
{
	init_structs (path, game);
	len_map (game);
	read_map (game);
	check_map (game);
	check_multi (game);
}

void events(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1L<<0, close_window, game);// con este loop o bucle podemos cerra la ventana desde la x
	mlx_hook(game->mlx_win, 2, 1, key_press, game);
}


int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		errors ("no se ha especificado un mapa");
	funcions (&game, av[1]);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map.width * 30, game.map.height * 50, "so_long");
	events (&game);
	mlx_loop(game.mlx);
	exit (EXIT_SUCCESS);
}
