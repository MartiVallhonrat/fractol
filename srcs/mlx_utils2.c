/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:38:46 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/29 19:40:29 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	handle_colors(int keycode, t_vars *vars)
{
	if (vars->color > 250 || vars->color < 5)
		return ;
	else if (keycode == 27)
	{
		if (vars->color <= 10)
			return ;
		vars->color -= 10;
	}
	else if (keycode == 24)
	{
		if (vars->color >= 250)
			return ;
		vars->color += 10;
	}
	if (vars->set == 'm')
		paint_mandelbrot(vars);
	else if (vars->set == 'j')
		paint_julia(vars);
	else if (vars->set == 'b')
		paint_burning(vars);
}

static void	recalc_coords(double x, double y, t_vars *data, t_complex *diff)
{
	if (x > 0)
	{
		data->limits.left = x - fabs(data->limits.left);
		data->limits.right = data->limits.left + diff->x;
	}
	else
	{
		data->limits.right = x + fabs(data->limits.right);
		data->limits.left = data->limits.right - diff->x;
	}
	if (y > 0)
	{
		data->limits.down = y - fabs(data->limits.down);
		data->limits.up = data->limits.down + diff->y;
	}
	else
	{
		data->limits.up = y + fabs(data->limits.up);
		data->limits.down = data->limits.up - diff->y;
	}
}

static void	recalc_screen(double x, double y, t_vars *data)
{
	t_complex	diff;

	x = data->limits.left + ((fabs(data->limits.left - data->limits.right)
				/ WIDTH) * x);
	y = data->limits.up - ((fabs(data->limits.up - data->limits.down)
				/ HEIGHT) * y);
	diff.x = fabs(data->limits.right - data->limits.left);
	diff.y = fabs(data->limits.up - data->limits.down);
	recalc_coords(x, y, data, &diff);
}

void	do_zoom_in(int x, int y, t_vars *data)
{
	double	tmp_down;
	double	tmp_up;
	double	tmp_right;
	double	tmp_left;

	recalc_screen(x, y, data);
	tmp_down = data->limits.down + (fabs(data->limits.down - data->limits.up)
			* 0.1);
	tmp_up = data->limits.up - (fabs(data->limits.down - data->limits.up)
			* 0.1);
	tmp_right = data->limits.right
		- (fabs(data->limits.left - data->limits.right) * 0.1);
	tmp_left = data->limits.left + (fabs(data->limits.left - data->limits.right)
			* 0.1);
	data->limits.down = tmp_down;
	data->limits.up = tmp_up;
	data->limits.right = tmp_right;
	data->limits.left = tmp_left;
	if (data->set == 'm')
		paint_mandelbrot(data);
	else if (data->set == 'j')
		paint_julia(data);
	else if (data->set == 'b')
		paint_burning(data);
}

void	do_zoom_out(t_vars *data)
{
	double	tmp_down;
	double	tmp_up;
	double	tmp_right;
	double	tmp_left;

	tmp_down = data->limits.down - (fabs(data->limits.down - data->limits.up)
			* 0.1);
	tmp_up = data->limits.up + (fabs(data->limits.down - data->limits.up)
			* 0.1);
	tmp_right = data->limits.right
		+ (fabs(data->limits.left - data->limits.right) * 0.1);
	tmp_left = data->limits.left - (fabs(data->limits.left - data->limits.right)
			* 0.1);
	data->limits.down = tmp_down;
	data->limits.up = tmp_up;
	data->limits.right = tmp_right;
	data->limits.left = tmp_left;
	if (data->set == 'm')
		paint_mandelbrot(data);
	else if (data->set == 'j')
		paint_julia(data);
	else if (data->set == 'b')
		paint_burning(data);
}
