/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:16:47 by ciclo             #+#    #+#             */
/*   Updated: 2023/01/29 15:16:47 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_structs(char *path, t_game *game)
{
	game->map.map = NULL;
	game->map.height = 0;
	game->map.width = 0;
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
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.width + 1));
	if (!game->map.map)
		return ;
	line = get_next_line(fd);
	if (!line)
		errors ("line");
	x = 0;
	while (x < game->map.height)
	{
		game->map.map[x] = (char *)malloc(sizeof(char) * ft_strlen(line));
		if (!game->map.map[x])
			return ;
		game->map.map[x] = line;
		line = get_next_line (fd);
		x++;
	}
	free (line);
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
	game->map.width = ft_strlen (line);
	while (*line)
	{
		if ((int)ft_strlen(line) != game->map.width)
			errors ("line != width");
		free (line);
		game->map.height++;
		line = get_next_line (fd);
	}
	line = NULL;
	close (fd);
}
