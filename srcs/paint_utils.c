/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:25:26 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/29 19:46:18 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(img->addr + offset)) = color;
}

void	color_screen_mandelbrot(t_vars *vars, t_limits *limits)
{
	t_complex	pixel;
	int			i;

	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			if (vars->set == 'm')
				i = (calc_iterations_mandelbrot(&pixel, limits) * 2 + 1);
			else if (vars->set == 'b')
				i = (calc_iterations_burning(&pixel, limits) * 2 + 1);
			if (i == 255)
				my_pixel_put(&(vars->img), pixel.x, pixel.y,
					create_trgb(0, vars->color, i, 0));
			else
				my_pixel_put(&(vars->img), pixel.x, pixel.y,
					create_trgb(0, i, i, i));
			(pixel.x)++;
		}
		(pixel.y)++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	color_screen_julia(t_vars *vars, t_limits *limits, t_complex *z)
{
	t_complex	pixel;
	int			i;

	pixel.y = 0;
	while (pixel.y < HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIDTH)
		{
			i = (calc_iterations_julia(&pixel, limits, z) * 2 + 1);
			if (i == 255)
				my_pixel_put(&(vars->img), pixel.x, pixel.y,
					create_trgb(0, 0, i, vars->color));
			else
				my_pixel_put(&(vars->img), pixel.x, pixel.y,
					create_trgb(0, i, i, i));
			(pixel.x)++;
		}
		(pixel.y)++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}
