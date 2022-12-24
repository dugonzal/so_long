/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:01 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/24 17:49:19 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


/* si hago itero una variable de la estrcura con -- o cambio su valor
	en el flujo del programa su valor se ve alterado en la ejecucion del programa
*/
int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		init_structs (av[1], &game);
		len_map (&game);
		read_map (&game);
		check_map (&game);
	}
	else
		errors ("no se ha especificado un mapa");
		//game.mlx = mlx_init();
		//game.mlx_win = mlx_new_window(game.mlx, game.map.width * 30, game.map.height * 50, "so_long");
		//mlx_loop(game.mlx);
	return (0);
}
