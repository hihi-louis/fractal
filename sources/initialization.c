/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:48:12 by tripham           #+#    #+#             */
/*   Updated: 2025/02/21 05:00:07 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	view_points(t_fractol *fractol)
{
	if (ft_strcmp(fractol->set, "julia") == 0)
	{
		fractol->min.x = -2.0;
		fractol->max.x = 2.0;
		fractol->min.y = -2.0;
		fractol->max.y = 2.0;
	}
	else if (ft_strcmp(fractol->set, "mandelbrot") == 0)
	{
		fractol->min.x = -3.0;
		fractol->max.x = 2.0;
		fractol->min.y = -2.5;
		fractol->max.y = 2.5;
	}
}

static void	initialize_julia(t_fractol *fractol, char **argv)
{
	if ((fractol -> c.x > 2.0 || fractol -> c.x < -2.0)
		|| (fractol -> c.y > 2.0 || fractol -> c.y < -2.0))
	{
		arg_guide("Argument for Julia set is invalid");
		exit (EXIT_FAILURE);
	}
}

void	initialize_fractol(t_fractol *fractol, char **argv)
{
	fractol->set = argv[1];
	fractol->max_iter = 100;
	if ((ft_strcmp(fractol->set, "julia")) != 0)
		initialize_julia(fractol, argv);
	fractol->mlx = mlx_init(WIDTH, HEIGHT, fractol->set, false);
	if (!fractol->mlx)
	{
		error_output("MLX42 inizialization failed");
		exit (EXIT_FAILURE);
	}
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img)
	{
		error_output("Image initialization failed");
		mlx_delete_image(fractol->mlx, fractol->img);
		mlx_close_window(fractol->mlx);
		exit (EXIT_FAILURE);
	}
	view_points(fractol);
	mlx_img_to_window(fractol->mlx, fractol->img, 0, 0);
}

