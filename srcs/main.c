/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:44:44 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/04 19:12:47 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	throw_error(void)
{
	ft_putstr_fd("INVALID INPUT!\nPlease write a valid set to visualize.", 2);
	ft_putstr_fd("\n\nCurrent available sets:\n\t- Mandelbrot\n\t", 2);
	ft_putstr_fd("- Julia 'value 1' 'value 2'\n\t- BurningShip\n", 2);
	exit(1);
}

static void	check_nan(int argc, char *argv[])
{
	int		i;
	char	*str;
	int		decimal;

	decimal = 0;
	while (--argc > 2)
	{
		i = 0;
		str = argv[argc];
		while (str[i])
		{
			if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'
					|| str[i] == '-' || str[i] == '+' || str[i] == ' '))
				throw_error();
			if ((str[i] == '-' || str[i] == '+')
				&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
				throw_error();
			if (str[i] == '.' && (decimal == 1 || i == 0 || str[i + 1] == '\0'))
				throw_error();
			if (str[i] == '.' && decimal == 0)
				decimal = 1;
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	char		*set;
	t_complex	values;

	if (argc == 2 || argc == 4)
	{
		set = argv[1];
		if (ft_strcmp(set, "Mandelbrot") == 0 && argc == 2)
			calc_mandelbrot();
		else if (ft_strcmp(set, "Julia") == 0 && argc == 4)
		{
			check_nan(argc, argv);
			values.x = ft_atoi_double(argv[2]);
			values.y = ft_atoi_double(argv[3]);
			calc_julia(&values);
		}
		else if (ft_strcmp(set, "BurningShip") == 0 && argc == 2)
			calc_burning();
		else
			throw_error();
	}
	else
		throw_error();
	return (0);
}
