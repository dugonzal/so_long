/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dugonzal <dugonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:31:41 by dugonzal          #+#    #+#             */
/*   Updated: 2023/01/16 22:31:44 by dugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	t_mlx	*e;
	t_mlx	ee;

	e = &ee;
	e->mlx = mlx_init();

	e->l = mlx_xpm_file_to_image(e->mlx, "i/test.xpm", &(e->x), &(e->y));
	e->w = mlx_new_window(e->mlx, e->x + 100, e->y, "ventana");

	mlx_put_image_to_window(e->mlx, e->w, e->l, e->x / 2, 10);
	mlx_put_image_to_window(e->mlx, e->w, e->l, 0, 0);
	mlx_loop(e->mlx);
}
