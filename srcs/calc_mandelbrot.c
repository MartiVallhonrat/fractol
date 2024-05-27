/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:02:45 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/29 19:10:39 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	calc_mandelbrot(void)
{
	t_vars		vars;

	vars.limits.left = -2.5;
	vars.limits.right = 1.5;
	vars.limits.up = 2;
	vars.limits.down = -2;
	vars.set = 'm';
	vars.mlx = mlx_init();
	vars.color = 10;
	if (!vars.mlx)
		exit(1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Mandelbrot");
	if (!vars.win)
	{
		free(vars.mlx);
		exit(1);
	}
	mlx_key_hook(vars.win, handle_key_input, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, handle_exit, &vars);
	mlx_mouse_hook(vars.win, handle_mouse_input, &vars);
	paint_mandelbrot(&vars);
	mlx_loop(vars.mlx);
}
