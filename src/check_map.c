/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:19:38 by lshonta           #+#    #+#             */
/*   Updated: 2022/12/23 20:35:50 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	check_map(t_game *game)
{
	int i;
	int len;

	i = 0;
	len = arr_size(game->map.map);
	while (game->map.map[0][i])
	{
		if (game->map.map[0][i] != '1' || game->map.map[len - 1][i] != '1')
			errors ("");
		i++;
	}
}