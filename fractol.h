/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:51:09 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/04 12:03:26 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include "libs/minilibx_macos/mlx.h"
# include "libs/libft/libft.h"

# define WIDTH 720
# define HEIGHT 720

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_limits
{
	double	left;
	double	right;
	double	up;
	double	down;
}	t_limits;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_limits	limits;
	char		set;
	t_complex	*c;
	int			color;
}	t_vars;

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int		ft_strcmp(char *s1, char *s2);
double	ft_atoi_double(const char *str);
void	calc_mandelbrot(void);
void	calc_julia(t_complex *c);
void	calc_burning(void);
int		handle_exit(t_vars *data);
int		handle_key_input(int keycode, t_vars *data);
void	handle_colors(int keycode, t_vars *vars);
int		handle_mouse_input(int mouse_code, int x, int y, t_vars *data);
void	do_zoom_in(int x, int y, t_vars *data);
void	do_zoom_out(t_vars *data);
void	paint_mandelbrot(t_vars *vars);
void	paint_julia(t_vars *vars);
void	paint_burning(t_vars *vars);
int		create_trgb(int t, int r, int g, int b);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	color_screen_mandelbrot(t_vars *vars, t_limits *limits);
int		calc_iterations_mandelbrot(t_complex *pixel, t_limits *limits);
void	color_screen_julia(t_vars *vars, t_limits *limits, t_complex *c);
int		calc_iterations_julia(t_complex *pixel, t_limits *limits, t_complex *c);
int		color_screen_burning(t_vars *vars, t_limits *limits);
int		calc_iterations_burning(t_complex *pixel, t_limits *limits);

#endif
