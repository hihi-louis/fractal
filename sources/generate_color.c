/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 02:38:55 by tripham           #+#    #+#             */
/*   Updated: 2025/02/21 04:28:13 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static uint32_t	get_pixel(uint32_t r, uint32_t g, uint32_t b, uint32_t a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}

void	generate_color(t_fractol *fractol, int inter, double move)
{
	t_color *pixel;

	pixel = &(fractol->pixel);
	if (inter == fractol->max_iter)
	{
		pixel->color = get_pixel(0, 0, 0, 255);
		return ;
	}
	pixel->red = (uint32_t)(sin(move) * 127.5 + 127.5);
	pixel->green = (uint32_t)(sin(move + 2 * M_PI / 3) * 127.5 + 127.5);
	pixel->blue = (uint32_t)(sin(move + 4 * M_PI / 3) * 127.5 + 127.5);
	pixel->color = get_pixel(pixel->red, pixel->green, pixel->blue, 255);
}
