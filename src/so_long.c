/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:01 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/15 23:02:47 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game game;


	if (ac == 2)
	{
		init_map (av[1]);
		//game.mlx = mlx_init();
		//game.mlx_win = mlx_new_window(game.mlx, 1000, 800, "so_long");
		//mlx_loop(game.mlx);
	}
	return (0);
}