/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:15:15 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/28 23:03:58 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (game->map.map[y] != 0)
	{
		x = 0;
		while (game->map.map[y][x] != 0)
		{
			if (game->map.map[y][x] == '0')
                  mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.floor, (x * 32), (y * 32));
			else if (game->map.map[y][x] == 'P')
				mlx_put_image_to_window (game->mlx, game->mlx_win, game->img.player, (x * 32), (y * 32));
			x++;
		}
		y++;
	}
}

void	mov_w(t_game *game)
{
    if (game->map.map[game->player.y - 1][game->player.x] != '1' && game->map.map[game->player.y - 1][game->player.x] != 'E')
    {
        if (game->map.map[game->player.y - 1][game->player.x] == 'C')
            game->player.collectibles--;
        game->map.map[game->player.y][game->player.x] = '0';
        game->map.map[game->player.y - 1][game->player.x] = 'P';
        game->player.y--;
        get (game);
        printf ("moves -> %d\n", game->player.moves++);
    }
    if (game->map.map[game->player.y - 1][game->player.x] == 'E' && game->player.collectibles == 0)
        win (game);
}

void mov_s(t_game *game)
{
    if (game->map.map[game->player.y + 1][game->player.x] != '1' && game->map.map[game->player.y + 1][game->player.x] != 'E')
    {
        if (game->map.map[game->player.y + 1][game->player.x] == 'C')
            game->player.collectibles--;
       game->player.y++;
       game->map.map[game->player.y][game->player.x] = 'P';
       if (game->map.map[game->player.y - 1][game->player.x] != 'E')
            game->map.map[game->player.y - 1][game->player.x] = '0';
        get (game);
        printf ("moves -> %d\n", game->player.moves++);
    }
    else if (game->map.map[game->player.y + 1][game->player.x] == 'E' && game->player.collectibles == 0)
        win (game);
}

int mov_a(t_game *game)
{
    if (game->map.map[game->player.y][game->player.x - 1] != '1' && game->map.map[game->player.y][game->player.x - 1] != 'E')
    {
        if (game->map.map[game->player.y][game->player.x - 1] == 'C')
            game->player.collectibles--;
       game->player.x--;
       game->map.map[game->player.y][game->player.x] = 'P';
       if (game->map.map[game->player.y][game->player.x] != 'E')
        game->map.map[game->player.y ][game->player.x + 1] = '0';
       get (game);
        printf ("moves -> %d\n", game->player.moves++);

    }
    else if (game->map.map[game->player.y][game->player.x - 1] == 'E' && game->player.collectibles == 0)
        win (game);
    return 0;
}

void mov_d(t_game *game)
{
    if (game->map.map[game->player.y][game->player.x + 1] != '1' && game->map.map[game->player.y][game->player.x + 1] != 'E')
    {
        if (game->map.map[game->player.y][game->player.x + 1] == 'C')
            game->player.collectibles--;
       game->player.x++;
       game->map.map[game->player.y][game->player.x] = 'P';
       if (game->map.map[game->player.y][game->player.x] != 'E')
         game->map.map[game->player.y ][game->player.x - 1] = '0';
       get (game);
        printf ("moves -> %d\n", game->player.moves++);

    }
    else if (game->map.map[game->player.y][game->player.x + 1] == 'E' && game->player.collectibles == 0)
        win (game);
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
