/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:26 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/29 21:25:20 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include	"../libft/include/libft.h"
# include	"../minilibx_macos/mlx.h"

# define Q 0x0C  // 12
# define W 0x77//13
# define A 0x61//0
# define S 0x73//1
# define D 0x64//2
# define ESC 0x35

# define AVATAR "images/avatar.xpm"
# define WALLS "images/wall.xpm"
# define FLOORS "images/floor.xpm"
# define EXIT_E "images/open-exit.xpm"
# define COLLECT	"images/collects.xpm"
# define GREEN	"\033[0;32m"
# define RED 	"\033[1;31m"
# define GREY 	"\033[0;90m"
# define CYAN	"\033[1;96m"
# define RESET 	"\033[0m"

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	char	*path;
	int		player;
	int		count;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		collectibles;
	int		collected;
	int		moves;
}	t_player;

typedef struct s_image
{
	void	*collects;
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
	t_map		map;
	t_image		img;
	t_player	player;
}	t_game;

void	init_structs(char *path, t_game *game);
void	len_map(t_game *game);
void	read_map(t_game *game);
void	assign_caracteres_map(t_game *game);
void	print_map(t_game *game);
void	check_map(t_game *game);
void	errors(char *str);
int		key_press(int keycode, t_game *game);
void	get_images(t_game *game);
void	get_posicion_player(t_game *game);
void	win(t_game *game);
int		close_window(t_game *game);

#endif
