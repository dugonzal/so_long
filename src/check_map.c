/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/23 21:36:18 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	check_map(t_game *game)
{
	int i;
	int err;
	int len;

	i = 0;
	err = 0;
	len = arr_size (game->map.map) -1;
	while (game->map.width--)
	{
		if (game->map.map[0][i] != '1' || game->map.map[len][i] != '1')
			err++;

		printf ("%c",game->map.map[len][i]);
		i++;
	}
	printf ("[%d]", err);
	if (err > 1)
		errors ("");
}
