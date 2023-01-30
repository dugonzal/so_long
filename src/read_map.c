/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:16:47 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/30 23:08:12 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_structs(char *path, t_game *game)
{
	game->map.map = NULL;
	game->map.y = 0;
	game->map.x = 0;
	game->map.player = 0;
	game->map.path = path;
	game->player.collectibles = 0;
	game->player.collected = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.moves = 1;
}

static	void	check_ext(char *path)
{
	char	*check;

	check = ft_strrchr(path, '.');
	if (!check || ft_strncmp(".ber", check, 4) || ft_strlen (path) < 4)
		errors ("ext");
}

static int	open_fd(char *path, int fd)
{
	fd = open (path, O_RDONLY | O_NOFOLLOW);
	if (!fd || fd == -1)
	{
		errors ("fd.open");
		close (fd);
	}
	return (fd);
}

void	read_map(t_game *game)
{
	int		x;
	int		fd;
	char	*line;

	fd = 0;
	fd = open_fd(game->map.path, fd);
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.x + 1));
	if (!game->map.map)
		return ;
	line = get_next_line(fd);
	if (!line)
		errors ("line");
	x = 0;
	while (x < game->map.y)
	{
		game->map.map[x] = (char *)malloc(sizeof(char) * ft_strlen(line));
		if (!game->map.map[x])
			return ;
		game->map.map[x] = line;
		line = get_next_line (fd);
		free (line);
		x++;
	}
	game->map.map[x] = NULL;
	close (fd);
}

void	len_map(t_game *game)
{
	int		fd;
	char	*line;

	check_ext(game->map.path);
	fd = 0;
	fd = open_fd(game->map.path, fd);
	line = get_next_line (fd);
	game->map.x = ft_strlen (line);
	while (*line)
	{
		if ((int)ft_strlen(line) != game->map.x)
			errors ("la linea es diferente de la anchura");
		game->map.y++;
		line = get_next_line (fd);
		free (line);
	}
	if (game->map.x == game->map.y)
		errors ("el mapa es cuadrado y no rectangular");
	line = NULL;
	close (fd);
}
