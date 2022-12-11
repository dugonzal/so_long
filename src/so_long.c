/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 14:21:01 by ciclo             #+#    #+#             */
/*   Updated: 2022/12/11 15:32:58 by ciclo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

int	main(void)
{
	char	*s;
	int		fd;
	int		c;

	fd = open("../maps/fd.txt", O_RDONLY);
	c = 2 ;
	while (c--)
	{
		s = get_next_line(fd);
		printf("{%s}", s);
		free (s);
	}
	close(fd);
	return (0);
}
