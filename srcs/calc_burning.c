/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_burning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:31:15 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/29 19:15:25 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	calc_burning(void)
{
	t_vars	vars;

	vars.limits.left = -2.9;
	vars.limits.right = 1.5;
	vars.limits.up = 1.5;
	vars.limits.down = -2.9;
	vars.set = 'b';
	vars.mlx = mlx_init();
	vars.color = 10;
	if (!vars.mlx)
		exit(1);
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Burning Ship");
	if (!vars.win)
	{
		free(vars.mlx);
		exit(1);
	}
	mlx_key_hook(vars.win, handle_key_input, &vars);
	mlx_hook(vars.win, ON_DESTROY, 0, handle_exit, &vars);
	mlx_mouse_hook(vars.win, handle_mouse_input, &vars);
	paint_burning(&vars);
	mlx_loop(vars.mlx);
}
