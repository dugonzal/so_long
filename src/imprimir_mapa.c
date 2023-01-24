/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imprimir_mapa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:04:29 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/24 19:14:25 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// con esta funcion puedo imprimir los cambios del mapa
// una vez leemos el mapa, se esta guardando en la estructura y la idea es alterar el mapa que estamos guradando en la
// estructura una vez se vaya moviendo el jugador por el mapa;
void print_game(t_game *game)
{
    int y;
    int x;

    y = 0;
    while (game->map.map[y])
    {
        x = 0;
        while (game->map.map[y][x])
        {
            printf ("%c", game->map.map[y][x]);
            x++;
        }
        y++;
    }
}