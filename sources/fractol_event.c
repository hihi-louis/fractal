/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:18:43 by tripham           #+#    #+#             */
/*   Updated: 2025/02/21 05:05:02 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	fractol_ctrl(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(fractol->mlx, fractol->img);
		mlx_close_window(fractol->mlx);
		ft_putendl_fd("Closed the window", 1);
		exit(EXIT_SUCCESS);
	}
	else if (keydata.key == MLX_KEY_TAB && keydata.action == MLX_PRESS)
		input_guide();
}

void	fractol_zoom(double xdelta, double ydelta, void *param)
{
	int32_t		pixel_x;
	int32_t		pixel_y;
	double		zoom_factor;
	t_complex	mouse;
	t_fractol	*fractol;

	(void)xdelta;
	fractol = (t_fractol *)param;
	mlx_get_mouse_pos(fractol->mlx, &pixel_x, &pixel_y);
	convert_pixel_to_complex(fractol, pixel_x, pixel_y, &mouse);
	if (ydelta > 0)
		zoom_factor = 0.9;
	else if (ydelta < 0)
		zoom_factor = 1.1;
	else
		return ;
	if ((fractol->max.x - fractol->min.x) < 0.0001 && zoom_factor < 1.0)	// Prevent excessive zooming (limit fractal area)
		return;
	if ((fractol->max.x - fractol->min.x) > 4.0 && zoom_factor > 1.0)
		return;
	fractol->min.x = mouse.x + (fractol->min.x - mouse.x) * zoom_factor;
	fractol->min.y = mouse.y + (fractol->min.y - mouse.y) * zoom_factor;
	fractol->max.x = mouse.x + (fractol->max.x - mouse.x) * zoom_factor;
	fractol->max.y = mouse.y + (fractol->max.y - mouse.y) * zoom_factor;
	rendering(fractol);
}

void	fractol_shift(void *param)
{
	t_complex	shift_factor;
	double		range_x;
	double		range_y;
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	shift_factor.x = 0.0;
	shift_factor.y = 0.0;
	range_x = fractol->max.x - fractol->min.x;
	range_y = fractol->max.y - fractol->min.y;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
		shift_factor.x = 0.05 * (range_x + range_y) / 2;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		shift_factor.x = -(0.05 * (range_x + range_y) / 2);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		shift_factor.y = -(0.05 * (range_x + range_y) / 2);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		shift_factor.y = 0.05 * (range_x + range_y) / 2;
	else
		return ;
	fractol->min.x += range_x * shift_factor.x;
	fractol->max.x += range_x * shift_factor.x;
	fractol->min.y += range_y * shift_factor.y;
	fractol->max.y += range_y * shift_factor.y;
	rendering(fractol);
}
