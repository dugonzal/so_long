/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:16:47 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/22 21:07:16 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_structs(char *file_d, t_game *game)
{
	game->map.map = NULL;
	game->map.height = 0;
	game->map.width = 0;
	game->map.file_d = file_d;
	game->player.collectibles = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.scape = 0;
}

static void	check_ext(char *path)
{
	char *check;

	if (ft_strlen (str) < 4)
		errors ("ext.len");
	check = ft_strrchr(path, '.');
	if (!check ||ft_strncmp(".ber", check, ft_strlen (check)))
		errors ("ext");
}


void	len_map(t_game *game)
{
	int		fd;
	char	*line;

	check_ext(game->map.file_d);
	fd = open (game->map.file_d, O_RDONLY);
	if (!fd)
		errors ("fd.open");
	line = get_next_line (fd);
	while (line[game->map.width])
		game->map.width++;
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
	int i;
	int fd;
	char *line;

	fd = open (game->map.file_d, O_RDONLY);
	i = 0;
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.width + 1));
	if (!game->map.map)
		return ;
	line = NULL;
	line = get_next_line(fd);
	if (!line)
		errors ("line");
	while (*line)
	{
		game->map.map[i] = line;
		line = get_next_line (fd);
		i++;
	}
	game->map.map[i] = NULL;
	free (line);
	close (fd);
}
