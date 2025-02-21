/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:17:47 by tripham           #+#    #+#             */
/*   Updated: 2025/02/21 04:10:39 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	convert_pixel_to_complex(t_fractol *fractol, int x, int y , t_complex *c)
{
	c->x = fractol->min.x + (fractol->max.x - fractol->min.x) / WIDTH * x;
	c->y = fractol->min.y + (fractol->max.y - fractol->min.y) / HEIGHT * y;
}

static void	amount_of_escape(t_fractol *fractol)
{
	double zx;
	double zy;
	double cx;
	double cy;
	double tmp;

	zx = fractol->z.x;
	zy = fractol->z.y;
	cx = fractol->c.x;
	cy = fractol->c.y;
	fractol->iter = 0;
	while ((zx * zx) + (zy * zy) < 4.0 && fractol->iter < fractol->max_iter)
	{
		tmp = (zx * zx) - (zy * zy) + cx;
		zy = 2 * zx * zy + cy;
		zx = tmp;
		fractol->iter++;
	}
	tmp = fabs(sqrt(zx * zx + zy * zy));
	if (tmp > 1.0 && log(tmp) > 0.0)
		fractol->move = fractol->iter - (log(log(tmp)) / log(2.0));
	else
		fractol->move = 0.0;
}

static void	julia(int x , int y, t_fractol *fractol)
{
	fractol->iter = 0;
	convert_pixel_to_complex(fractol, x, y, &(fractol->c));
	amount_of_escape(fractol);
	generate_color(fractol, fractol->iter, fractol->move);
}

static void	mandelbrot(int x, int y, t_fractol *fractol)
{
	fractol->z.x = 0;
	fractol->z.y = 0;
	fractol->iter = 0;
	convert_pixel_to_complex(fractol, x, y, &(fractol->c));
	generate_color(fractol, fractol->iter, fractol->move);
}
void	rendering(t_fractol *fractol)
{
	int x;
	int y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (ft_strcmp((fractol->set), "julia") == 0)
				julia(x, y, fractol);
			if (ft_strcmp((fractol->set), "mandelbrot") == 0)
				mandelbrot(x, y, fractol);
			mlx_put_pixel(fractol->img, x, y, fractol->pixel.color);
			y++;
		}
		x++;
	}
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}