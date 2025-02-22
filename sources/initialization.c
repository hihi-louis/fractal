/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:48:12 by tripham           #+#    #+#             */
/*   Updated: 2025/02/22 03:51:17 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	view_points(t_fractol *fractol)
{
	if (ft_strcmp(fractol->set, "julia"))
	{
		fractol->real.min = -1.7;
		fractol->real.max = 1.7;
		fractol->imag.min = -1.7;
		fractol->imag.max = 1.7;
	}
	else if (ft_strcmp(fractol->set, "mandelbrot"))
	{
		fractol->real.min = -2.0;
		fractol->real.max = 1.0;
		fractol->imag.min = -1.5;
		fractol->imag.max = 1.5;
	}
}

void	initialize_julia(t_fractol *fractol, char **argv)
{
	if (!argv[2] || !argv[3])
	{
		fractol_error("Argument requires [signed_double_a] [signed_double_b].\n"
			"Example: ./fractol julia -0.4 0.6");
		exit(EXIT_FAILURE);
	}
	fractol->julia_c.x = ft_atof(argv[2]);
	fractol->julia_c.y = ft_atof(argv[3]);
}

void	initialize_fractol(t_fractol *fractol, char **argv)
{
	fractol->set = argv[1];
	if (ft_strcmp(argv[1], "julia"))
	{
		fractol->type = JULIA;
		initialize_julia(fractol, argv);
	}
	fractol->mlx = mlx_init(WIDTH, HEIGHT, fractol->set, false);
	if (!(fractol->mlx))
	{
		fractol_error("Failed to initialize MLX42 library.");
		exit (EXIT_FAILURE);
	}
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!(fractol->image))
	{
		fractol_error("Failed to create a new image.");
		mlx_delete_image(fractol->mlx, fractol->image);
		mlx_close_window(fractol->mlx);
		exit (EXIT_FAILURE);
	}
	mlx_image_to_window(fractol->mlx, fractol->image, 0, 0);
	fractol_guide();
	fractol->max_iter = 100;
	fractol->change_rate = 0.1;
	view_points(fractol);
}
