/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:50:49 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/29 19:31:28 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_exit(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

static void	handle_arrows_2(int keycode, t_vars *data)
{
	if (keycode == 125)
	{
		data->limits.up -= (fabs(data->limits.up - data->limits.down)
				/ 100) * 5;
		data->limits.down -= (fabs(data->limits.up - data->limits.down)
				/ 100) * 5;
	}
	else if (keycode == 126)
	{
		data->limits.down += (fabs(data->limits.up - data->limits.down)
				/ 100) * 5;
		data->limits.up += (fabs(data->limits.up - data->limits.down)
				/ 100) * 5;
	}
}

static void	handle_arrows(int keycode, t_vars *data)
{
	if (keycode == 123)
	{
		data->limits.left -= (fabs(data->limits.left - data->limits.right)
				/ 100) * 5;
		data->limits.right -= (fabs(data->limits.left - data->limits.right)
				/ 100) * 5;
	}
	else if (keycode == 124)
	{
		data->limits.right += (fabs(data->limits.left - data->limits.right)
				/ 100) * 5;
		data->limits.left += (fabs(data->limits.left - data->limits.right)
				/ 100) * 5;
	}
	else
		handle_arrows_2(keycode, data);
	if (data->set == 'm')
		paint_mandelbrot(data);
	else if (data->set == 'j')
		paint_julia(data);
	else if (data->set == 'b')
		paint_burning(data);
}

int	handle_key_input(int keycode, t_vars *data)
{
	if (keycode == 53)
		handle_exit(data);
	if (keycode >= 123 && keycode <= 126)
		handle_arrows(keycode, data);
	if (keycode == 27 || keycode == 24)
		handle_colors(keycode, data);
	return (0);
}

int	handle_mouse_input(int mouse_code, int x, int y, t_vars *data)
{
	if (mouse_code == 4)
		do_zoom_out(data);
	if (mouse_code == 5)
		do_zoom_in(x, y, data);
	return (0);
}
