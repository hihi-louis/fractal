/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:26:46 by tripham           #+#    #+#             */
/*   Updated: 2025/02/21 04:32:13 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;
	
	if (check_validation_arg(argc, argv))
		return (EXIT_FAILURE);
	initialize_fractol(&fractol, argv);
	rendering(&fractol);
	input_guide();
	mlx_key_hook(fractol.mlx, fractol_ctrl, &fractol);
	mlx_scroll_hook(fractol.mlx, fractol_zoom, &fractol);
	mlx_loop_hook(fractol.mlx, fractol_shift, &fractol);
	mlx_loop(fractol.mlx);
	return (EXIT_SUCCESS);
}