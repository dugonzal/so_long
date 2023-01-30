/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:15:15 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/30 22:35:08 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mov_w(t_game *game)
{
	if (game->map.map[game->player.y - 1][game->player.x] != '1' \
	&& game->map.map[game->player.y - 1][game->player.x] != 'E')
	{
		if (game->map.map[game->player.y - 1][game->player.x] == 'C')
			game->player.collectibles--;
		game->map.map[game->player.y][game->player.x] = '0';
		game->map.map[game->player.y - 1][game->player.x] = 'P';
		game->player.y--;
		get_images (game);
		printf (RED"moves -> %d\n"RESET, game->player.moves++);
	}
	if (game->map.map[game->player.y - 1][game->player.x] == 'E' \
	&& game->player.collectibles == 0)
		win (game);
}

void	mov_s(t_game *game)
{
	if (game->map.map[game->player.y + 1][game->player.x] != '1' \
	&& game->map.map[game->player.y + 1][game->player.x] != 'E')
	{
		if (game->map.map[game->player.y + 1][game->player.x] == 'C')
			game->player.collectibles--;
		game->player.y++;
		game->map.map[game->player.y][game->player.x] = 'P';
		game->map.map[game->player.y - 1][game->player.x] = '0';
		get_images (game);
		printf (CYAN"moves -> %d\n"RESET, game->player.moves++);
	}
	else if (game->map.map[game->player.y + 1][game->player.x] == 'E' \
	&& game->player.collectibles == 0)
		win (game);
}

void	mov_a(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x - 1] != '1' \
	&& game->map.map[game->player.y][game->player.x - 1] != 'E')
	{
		if (game->map.map[game->player.y][game->player.x - 1] == 'C')
			game->player.collectibles--;
		game->player.x--;
		game->map.map[game->player.y][game->player.x] = 'P';
		game->map.map[game->player.y][game->player.x + 1] = '0';
		get_images (game);
		printf (GREY"moves -> %d\n"RESET, game->player.moves++);
	}
	else if (game->map.map[game->player.y][game->player.x - 1] == 'E' \
	&& game->player.collectibles == 0)
		win (game);
}

void	mov_d(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x + 1] != '1' \
	&& game->map.map[game->player.y][game->player.x + 1] != 'E')
	{
		if (game->map.map[game->player.y][game->player.x + 1] == 'C')
			game->player.collectibles--;
		game->player.x++;
		game->map.map[game->player.y][game->player.x] = 'P';
		game->map.map[game->player.y][game->player.x - 1] = '0';
		get_images (game);
		printf (GREEN"moves -> %d\n"RESET, game->player.moves++);
	}
	else if (game->map.map[game->player.y][game->player.x + 1] == 'E' \
	&& game->player.collectibles == 0)
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
