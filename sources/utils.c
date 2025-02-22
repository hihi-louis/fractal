/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:08:06 by tripham           #+#    #+#             */
/*   Updated: 2025/02/22 03:52:54 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	check_float(char *str)
{
	int	decimal_point;
	int	digits;

	decimal_point = 0;
	digits = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str == '.')
		{
			if (decimal_point)
				return (0);
			decimal_point = 1;
		}
		else if (ft_isdigit((unsigned char) *str))
			digits = 1;
		else
			return (0);
		str++;
	}
	return (digits);
}

int	check_validation_extra_args(int argc, char **argv)
{
	if (argc == 3 && ft_strcmp(argv[1], "julia"))
	{
		if (!check_float(argv[2]))
			fractol_error("Invalid argument type");
		return (check_float(argv[2]));
	}
	else if (argc == 4 && ft_strcmp(argv[1], "julia"))
	{
		if (!check_float(argv[2]) || !check_float(argv[3]))
			fractol_error("Invalid argument type");
		return (check_float(argv[2]) && check_float(argv[3]));
	}
	fractol_error("Invalid extra arguments");
	return (0);
}

int	check_validation_arg(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = (ft_strcmp(argv[1], "mandelbrot") || ft_strcmp(argv[1], "julia"));
		if (i == 0)
			fractol_error("Invalid argument: <fractal set>");
		return (i);
	}
	else
		return (check_validation_extra_args(argc, argv));
}
