/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:18:43 by tripham           #+#    #+#             */
/*   Updated: 2025/02/22 17:41:37 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractol_ctrl(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(fractol->mlx, fractol->image);
		mlx_close_window(fractol->mlx);
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_SUBTRACT)
		&& fractol->max_iter > 5)
		fractol->max_iter *= 0.9;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_KP_ADD)
		&& fractol->max_iter < 500)
	{
		fractol->max_iter *= 1.1;
		if (fractol->max_iter >= 500)
			fractol->max_iter = 500;
	}
}

void	fractol_arrow(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	fractol->real.delta = fractol->real.max - fractol->real.min;
	fractol->imag.delta = fractol->imag.max - fractol->imag.min;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
	{
		fractol->real.min += fractol->real.delta * fractol->change_rate;
		fractol->real.max += fractol->real.delta * fractol->change_rate;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
	{
		fractol->real.min -= fractol->real.delta * fractol->change_rate;
		fractol->real.max -= fractol->real.delta * fractol->change_rate;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
	{
		fractol->imag.min -= fractol->imag.delta * fractol->change_rate;
		fractol->imag.max -= fractol->imag.delta * fractol->change_rate;
	}
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
	{
		fractol->imag.min += fractol->imag.delta * fractol->change_rate;
		fractol->imag.max += fractol->imag.delta * fractol->change_rate;
	}
}

void	fractol_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	double		mouse_r;
	double		mouse_i;
	double		zoom;

	(void) xdelta;
	fractol = (t_fractol *)param;
	mlx_get_mouse_pos(fractol->mlx, &(fractol->pixel_x), &(fractol->pixel_y));
	convert_pixel_to_complex(&mouse_r, &mouse_i, fractol);
	if (ydelta > 0)
		zoom = 0.9;
	else if (ydelta < 0)
		zoom = 1.1;
	else
		return ;
	fractol->real.min = mouse_r + (fractol->real.min - mouse_r) * zoom;
	fractol->real.max = mouse_r + (fractol->real.max - mouse_r) * zoom;
	fractol->imag.min = mouse_i + (fractol->imag.min - mouse_i) * zoom;
	fractol->imag.max = mouse_i + (fractol->imag.max - mouse_i) * zoom;
}
