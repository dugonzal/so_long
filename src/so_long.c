/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:01 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/25 18:02:53 by ciclo            ###   ########.fr       */
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

int	ft_exit(t_game *data)
{
	(void) *data;
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		init_structs (av[1], &game);
		len_map (&game);
		read_map (&game);
		check_map (&game);
		check_multi (&game);
		game.mlx = mlx_init();
		game.mlx_win = mlx_new_window(game.mlx, game.map.width * 30, game.map.height * 50, "so_long");
		mlx_hook(game.mlx_win, 17, 0, ft_exit, &game);// con este loop o bucle podemos cerra la ventana desde la x
		mlx_loop(game.mlx);
	}
	else
		errors ("no se ha especificado un mapa");
	return (0);
}
