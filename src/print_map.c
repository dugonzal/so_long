/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:19:55 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/27 10:35:45 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void    print_map(t_game *game)
{
    int y;
    
    y = 0;
    while (game->map.map[y])
    {
        printf ("%s", game->map.map[y]);
        
        y++;
    }
    printf ("\n");
}