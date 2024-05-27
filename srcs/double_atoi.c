/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:37:49 by mvallhon          #+#    #+#             */
/*   Updated: 2024/02/29 19:14:46 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_atoi_double(const char *str)
{
	double	res;
	double	negative;
	int		decimal;

	negative = 1;
	res = 0;
	decimal = 0;
	while (*str && *str == ' ')
		++str;
	if (*str == '-')
		negative = -1;
	while (*str && ((*str >= '0' && *str <= '9') || *str == '.'))
	{
		if (decimal > 0)
			decimal *= 10;
		if (*str == '.')
			decimal = 1;
		else
			res = res * 10 + (*str - 48);
		++str;
	}
	if (decimal)
		res /= decimal;
	return (res * negative);
}
