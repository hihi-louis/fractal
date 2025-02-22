/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:38:55 by tripham           #+#    #+#             */
/*   Updated: 2025/02/22 03:53:14 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

uint32_t	get_pixel(uint32_t red, uint32_t green, uint32_t blue, uint32_t a)
{
	return (red << 24 | green << 16 | blue << 8 | a);
}

void	generate_color(t_fractol *fractol)
{
	double	t;

	if (fractol->iter == fractol->max_iter)
	{
		fractol->get.color = get_pixel(0, 0, 0, 255);
		return ;
	}
	t = (double)fractol->iter / fractol->max_iter;
	fractol->get.red = (int)(16 * (1 - t) * t * t * t * 255);
	fractol->get.green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	fractol->get.blue = (int)(5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	fractol->get.alpha = 255;
	fractol->get.color = get_pixel(fractol->get.red, fractol->get.green,
			fractol->get.blue, fractol->get.alpha);
}
