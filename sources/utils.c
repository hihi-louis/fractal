/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:08:06 by tripham           #+#    #+#             */
/*   Updated: 2025/02/21 01:06:59 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	check_float(char *str)
{
	int		decimal_flag;
	int		digit_count;

	decimal_flag = 0;
	digit_count = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str) && *str != '.')
			return (0);
		else if (*str == '.')
		{
			if (decimal_flag || digit_count == 0)
				return (0);
			decimal_flag = digit_count;
		}
		else
			digit_count++;
		str++;
	}
	return (digit_count - decimal_flag);
}

int	check_validation_arg(int argc, char **argv)
{
	if (argc < 2 || argc == 3 || argc > 4)
		return (arg_guide("Invalid number of arguments"));
	if (ft_strcmp(argv[1], "mandelbrot") != 0)
	{
		if (argc != 2)
			return (arg_guide("Invalid number of arguments"));
		else
			return (0);
	}
	else if (ft_strcmp(argv[1], "julia") != 0)
	{
		if (argc != 4)
			return (arg_guide("Invalid number of arguments"));
		else
		{
			if (!check_float(argv[2]) || !check_float(argv[3]))
				return (arg_guide("Invalid arguments"));
			else
				return (0);
		}
	}
	else
		return (arg_guide("Invalid arguments: fractal name"));
}
