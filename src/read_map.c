/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:16:47 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/24 21:32:20 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_structs(char *path, t_game *game)
{
	game->map.map = NULL;
	game->map.height = 0;
	game->map.width = 0;
	game->map.path = path;
	game->player.collectibles = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.scape = 0;
}

static	void	check_ext(char *path)
{
	char	*check;

	check = ft_strrchr(path, '.');
	if (!check || ft_strncmp(".ber", check, ft_strlen (check)) \
	|| ft_strlen (path) < 4)
		errors ("ext");
}

static int	open_fd(char *path, int fd)
{
	fd = open (path, O_RDONLY | __O_NOFOLLOW);
	if (!fd || fd == -1)
	{
		errors ("fd.open");
		close (fd);
	}
	return (fd);
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
		game->map.height++;
		free (line);
		line = get_next_line (fd);
	}
	line = NULL;
	close (fd);
}

void	read_map(t_game *game)
{
	int		i;
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
	i = 0;
	while (i < game->map.height)
	{
		game->map.map[i] = line;
		line = get_next_line (fd);
		i++;
	}
	free (line);
	game->map.map[i] = NULL;
	close (fd);
}
