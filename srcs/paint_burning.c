/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_burning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:48:38 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/29 19:42:24 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	calc_iterations_burning(t_complex *pixel, t_limits *limits)
{
	t_complex	z;
	t_complex	c;
	int			i;
	double		tmp_z;

	z.x = 0;
	z.y = 0;
	c.x = limits->left + ((fabs(limits->left - limits->right) / WIDTH)
			* pixel->x);
	c.y = limits->up - ((fabs(limits->up - limits->down) / HEIGHT) * pixel->y);
	i = 0;
	while (i < 127)
	{
		if (z.y != 0)
			tmp_z = pow(fabs(z.x), 2) + (pow(fabs(z.y), 2) * -1) + c.x;
		else
			tmp_z = pow(fabs(z.x), 2) + pow(fabs(z.y), 2) + c.x;
		z.y = 2 * (fabs(z.x) * fabs(z.y)) + c.y;
		z.x = tmp_z;
		if (z.x > 20 || z.x < -20 || z.y > 20 || z.y < -20)
			break ;
		i++;
	}
	return (i);
}

void	paint_burning(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img,
			&(vars->img.bits_per_pixel), &(vars->img.line_length),
			&(vars->img.endian));
	color_screen_mandelbrot(vars, &(vars->limits));
}
