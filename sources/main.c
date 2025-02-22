/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:26:46 by tripham           #+#    #+#             */
/*   Updated: 2025/02/22 03:41:44 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc < 2 || !check_validation_arg(argc, argv))
		return (fractol_guide());
	initialize_fractol(&fractol, argv);
	mlx_key_hook(fractol.mlx, fractol_ctrl, &fractol);
	mlx_loop_hook(fractol.mlx, fractol_arrow, &fractol);
	mlx_loop_hook(fractol.mlx, rendering, &fractol);
	mlx_scroll_hook(fractol.mlx, fractol_scroll, &fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (0);
}
