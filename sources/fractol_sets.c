/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:39:00 by tripham           #+#    #+#             */
/*   Updated: 2025/02/22 03:52:41 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	convert_pixel_to_complex(double *r, double *i, t_fractol *fractol)
{
	double	pixel_width;
	double	pixel_height;

	pixel_width = (fractol->real.max - fractol->real.min) / WIDTH;
	pixel_height = (fractol->imag.max - fractol->imag.min) / HEIGHT;
	*r = fractol->real.min + ((double) fractol->pixel_x * pixel_width);
	*i = fractol->imag.max - ((double) fractol->pixel_y * pixel_height);
}

void	julia(uint32_t x, uint32_t y, t_fractol *fractol)
{
	fractol->c.x = fractol->julia_c.x;
	fractol->c.y = fractol->julia_c.y;
	fractol->pixel_x = x;
	fractol->pixel_y = y;
	convert_pixel_to_complex(&(fractol->z.x), &(fractol->z.y), fractol);
	amount_of_escape(fractol);
	generate_color(fractol);
}

void	mandelbrot(uint32_t x, uint32_t y, t_fractol *fractol)
{
	fractol->z.x = 0.0;
	fractol->z.y = 0.0;
	fractol->pixel_x = x;
	fractol->pixel_y = y;
	convert_pixel_to_complex(&(fractol->c.x), &(fractol->c.y), fractol);
	amount_of_escape(fractol);
	generate_color(fractol);
}
