/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:15:15 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/25 11:02:14 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	mov_w(t_game *game)
{
    printf ("move w\n");
    (void)game;
    //printf ("%d", game->player.collectibles);
    return (0);
}
int mov_a(t_game *game)
{
    (void)game;
    printf ("move a\n");
    return (0);
}

int mov_d(t_game *game)
{
    (void)game;
    printf ("move d\n");
    return (0);
}

int mov_s(t_game *game)
{
    (void)game;
    printf ("move s\n");  
    return (0); 
}

/// @brief controlador de los eventos de teclado
/// @param keycode // evento de teclado detectado 
/// @param game  // estructura del juego
/// @return 
int	key_press(int keycode, t_game *game)
{
	if (keycode == Q || keycode == ESC)
		close_window(game);
    else if (keycode == W)
       mov_w (game);
    else if (keycode == D)
        mov_d(game);
    else if (keycode == A)
        mov_a(game);
    else if (keycode == S)
        mov_s (game);
	return (0);
}


/*

una vez que podemos detectar los eventos del teclado, necesitamos saber donde se encuentra el jugador para poder alterar el array bidimencional;
*/