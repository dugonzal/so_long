/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:01 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/30 22:29:17 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	events_hooks(t_game *game)
{
	mlx_hook(game->mlx_win, 17, 1, close_window, game);
	mlx_hook(game->mlx_win, 2, 1, key_press, game);
}

void	init_map(t_game *game, char *path)
{
	init_structs (path, game);
	len_map (game);
	read_map (game);
	check_map (game);
	assign_caracteres_map(game);
	get_posicion_player(game);
}

void	print_map(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.y)
	{
		printf("%s", game->map.map[y]);
		y++;
	}
}

/*
void	flood_fill(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'C')
	{
		printf ("coleccionado ->[%d]", game->player.collected--);
	}
}

void	flood_fill_while(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			flood_fill (game, x, y);
			x++;
		}
		y++;
	}
	if (game->player.collected == 0)
		return;

	//read_map (game);
	else
		errors ("no se han recogido todas las monedas");
}
*/

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		errors ("no se ha especificado un mapa");
	init_map (&game, av[1]);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.map.x * 32 - 30, \
	game.map.y * 32, "so_long");
	events_hooks (&game);
	get_posicion_player (&game);
	get_images (&game);
	mlx_loop(game.mlx);
}
