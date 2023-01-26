/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:01 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/27 00:36:53 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


/* si hago itero una variable de la estrcura con -- o cambio su valor
	en el flujo del programa su valor se ve alterado en la ejecucion del programa
*/

void	map(t_game *game, char *path)
{
	init_structs (path, game);
	len_map (game);
	read_map (game);
	check_map (game);
	assign_caracteres_map(game);	
}

void events(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1L<<0, close_window, game);// con este loop o bucle podemos cerra la ventana desde la x
	mlx_hook(game->mlx_win, 2, 1, key_press, game);
}

/*
void	get_posicion(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (game->map.map[y] )
	{
		x = 0;
		while (game->map.map[y][x] != 0)
		{
			if (game->map.map[y][x] == 'P')
			{
				printf ("%d %d", y, x);
				//game->player.x =  x;
				ft_printf ("hehehe");
			}
				
		}
		y++;	
	}
}*/

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		errors ("no se ha especificado un mapa");
	map (&game, av[1]);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map.width * 32 - 28, game.map.height * 32, "so_long");
	events (&game);
	get_images (&game); 
	//get_posicion (&game);
	mlx_loop(game.mlx);
	exit (EXIT_SUCCESS);
} 
