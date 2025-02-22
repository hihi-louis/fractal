/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:17:49 by tripham           #+#    #+#             */
/*   Updated: 2025/02/22 03:41:30 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	fractol_error(char *str)
{
	ft_putendl_fd(str, 2);
	return (1);
}

int	fractol_guide(void)
{
	ft_putstr_fd(
		"**************************************************\n"
		"*            FRACT-OL USAGE GUIDE                *\n"
		"**************************************************\n"
		"\nAvailable fractal sets:"
		"\n\t- mandelbrot"
		"\n\t- julia"
		"\n"
		"\n\nGuide for fract-ol usage:"
		"\n\tUsage: ./fractol [fractal_set_name]"
		"\n\tTo create a specific Julia set:"
		"\n\tUsage: ./fractol julia [signed_double_a] [signed_double_b]"
		"\n\nExamples for Julia sets:"
		"\n\t-0.4\t0.6"
		"\n\t0.285\t0.01"
		"\n\t0\t0.8"
		"\n\t-1.476\t0"
		"\n\t-0.12\t-0.77"
		"\n\nGeneral Guide:"
		"\n\t- ESC: Close the window and quit the program."
		"\n\t- Arrow keys (← ↑ ↓ →): Move the view."
		"\n\t- Scroll: Zoom in and out based on the mouse position."
		"\n\t- Keypad + / -: Increase or decrease iterations"
		"\n**************************************************\n", 1);
	return (1);
}
