/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:31:18 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/26 15:30:59 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	errors(char *str)
{
	printf ("Error\n %s\n", str);
	exit (1);
}

int	close_window(t_game *game)
{
	mlx_destroy_window (game->mlx, game->mlx_win);
	exit(EXIT_SUCCESS);
}
