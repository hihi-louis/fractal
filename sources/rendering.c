/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:17:47 by tripham           #+#    #+#             */
/*   Updated: 2025/02/22 03:53:05 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	amount_of_escape(t_fractol *fractol)
{
	double	tmp;
	double	zx;
	double	zy;
	double	cx;
	double	cy;

	zx = fractol->z.x;
	zy = fractol->z.y;
	cx = fractol->c.x;
	cy = fractol->c.y;
	fractol->iter = 0;
	if (fractol->type == JULIA && cx == 0)
	{
		cy = -cy;
	}
	while ((zx * zx) + (zy * zy) < 4.0 && fractol->iter < fractol->max_iter)
	{
		tmp = zx;
		zx = (zx * zx) - (zy * zy) + cx;
		zy = 2 * tmp * zy + cy;
		fractol->iter++;
	}
}

void	rendering(void *param)
{
	t_fractol	*fractol;
	uint32_t	x;
	uint32_t	y;

	fractol = (t_fractol *)param;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (ft_strcmp(fractol->set, "julia"))
				julia(x, y, fractol);
			if (ft_strcmp(fractol->set, "mandelbrot"))
				mandelbrot(x, y, fractol);
			mlx_put_pixel(fractol->image, x, y, fractol->get.color);
			y++;
		}
		x++;
	}
}
