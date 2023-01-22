/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:26 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/22 22:13:30 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/include/libft.h"
#include "../mlx_linux/mlx.h"

# define Q 53
# define W 13
# define A 0
# define S 1
# define D 2

#define avatar "./test.xpm"
typedef struct s_map
{
	char	**map;
	int		width; // anchura && lenght -> anchura
	int		height; // altura
	char	*path;
	int		player;
	int		count;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		collectibles;
	int		scape;
}	t_player;

typedef struct s_image
{
	void	*collect;
	void	*player;
	void	*wall;
	void	*floor;
	void	*exit;
	int		width;
	int		height;
}	t_image;


typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	void		*n;
	t_map		map;
	t_image		img;
	t_player	player;
}	t_game;

void	init_structs(char *path, t_game *game);
void	len_map(t_game *game);
void	read_map(t_game *game);
void	errors(char *str);
void	check_map(t_game *game);
void	assign_caracteres_map(t_game *game);
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);
void	map_images(t_game *game);
int		create_map(t_game *game);


#endif
