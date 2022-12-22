/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:16:47 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/21 22:20:22 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(char *file_d, 	t_game *game)
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

/*
void	check(char *str)
{
	int i;

	i = ft_strlen (str);
	printf ("%d", i);
	if (i < 3)
		err ("Extencion .ber no valid", 1);

}
*/

void	len_map(t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	fd = open (game->map.file_d, O_RDONLY);
	line = get_next_line (fd);
	if (!line)
		err ("err.map");
	while (line[game->map.width])
		game->map.width++;
	i = 0;
	while (*line)
	{
		if ((int)ft_strlen(line) != game->map.width)
		{
			ft_printf ("Error.Map\n");
			exit (EXIT_FAILURE);
		}
		game->map.height++;
		free (line);
		line = get_next_line (fd);
		i++;
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
	if (!fd)
		return ;
	i = 0;
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.width + 1));
	if (!game->map.map)
		return ;
	line = get_next_line(fd);
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
