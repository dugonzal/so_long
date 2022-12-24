/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:26 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/24 11:44:39 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/include/libft.h"
#include "../mlx_linux/mlx.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_map
{
	char	**map;
	int		width; // anchura
	int		height; // altura
	char	*path;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		collectibles;
	int		scape;
}	t_player;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	map;
	t_player	player;
}	t_game;

void	init_structs(char *file_d, 	t_game *game);
void	len_map(t_game *game);
void	read_map(t_game *game);
void	errors(char *str);
void	check_map(t_game *game);

#endif
