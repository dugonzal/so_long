/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/23 23:28:51 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map(t_game *game)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (game->map.width--)
	{
		if (game->map.map[0][i] != '1' || \
		game->map.map[arr_size (game->map.map) - 1][i] != '1')
			err++;
		i++;
	}
	printf ("[%d]", err);
	if (err > 1)
		errors ("");
}
