/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:26 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/24 19:28:58 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/include/libft.h"
#include "../minilibx_macos/mlx.h"

# define Q 0x0C  // 12
# define W 13
# define A 0
# define S 1
# define D 2

#define	black "images/black.xpm"
#define	walls "images/wall.xpm"
#define	portal "images/portal.xpm"
#define coin	"images/coin.xpm"
#define avatar "images/ava.xpm"
//necesito una estructura para guradar los tamaños de la imagenes por separado, icluir esa lista en laestructura de imagenes
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


typedef struct s_size
{
	int y_player;
	int x_player;
	int y_wall;
	int	x_wall;
}t_size;

typedef struct s_image
{
	void	*collect;
	void	*player;
	void	*wall;
	void	*floor;
	void	*exit;
	int		width;
	int		height;
	t_size	size;
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
void	errors(char *str);
void	check_map(t_game *game);
void	assign_caracteres_map(t_game *game);
int		close_window(t_game *game);
int		key_press(int keycode, t_game *game);
void	map_images(t_game *game);
void	create_map(t_game *game);

//funcion chorra para imrpimir
void print_game(t_game *game);


#endif
