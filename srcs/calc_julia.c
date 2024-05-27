/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:09:53 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/29 19:16:01 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	calc_julia(t_complex *c)
{
	t_vars	vars;

	vars.c = c;
	vars.set = 'j';
	vars.limits.left = -3;
	vars.limits.right = 3;
	vars.limits.up = 3;
	vars.limits.down = -3;
	vars.mlx = mlx_init();
	vars.color = 10;
	if (!vars.mlx)
		exit(1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Julia Set");
	if (!vars.win)
	{
		free(vars.mlx);
		exit(1);
	}
	mlx_key_hook(vars.win, handle_key_input, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, handle_exit, &vars);
	mlx_mouse_hook(vars.win, handle_mouse_input, &vars);
	paint_julia(&vars);
	mlx_loop(vars.mlx);
}
