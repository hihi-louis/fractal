/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:17:49 by tripham           #+#    #+#             */
/*   Updated: 2025/02/21 00:31:13 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	input_guide(void)
{
	ft_putendl_fd("<=======================================================>"
		"\n| \033[4mControl guide\033[0m\t\t\t\t\t\t|"
		"\n| ESC		- Exit program\t\t\t\t|"
		"\n| TAB		- Display control guide\t\t\t|"
		"\n| ARROW KEYS	-Panning\t\t\t\t|"
		"\n| \tUP	- Move up\t\t\t\t|"
		"\n| \tDOWN	- Move down\t\t\t\t|"
		"\n| \tRIGHT	- Move right\t\t\t\t|"
		"\n| \tLEFT	- Move left\t\t\t\t|"
		"\n| MOUSE		- Zooming\t\t\t\t|"
		"\n| \tSCROLL_UP	- Zoom in\t\t\t|"
		"\n| \tSCROLL_DOWN	- Zoom out\t\t\t|"
		"\n<=======================================================>",
		STDERR_FILENO);
}

void	error_output(char *message_error)
{
	ft_putstr_fd(" fractol: Error: ", STDERR_FILENO);
	ft_putstr_fd(message_error, STDERR_FILENO);
}
int	arg_guide(char *message_error)
{
	error_output(message_error);
	ft_putendl_fd("\nUsage: ./fractol [fractal_name]", STDERR_FILENO); // douple check
	return (1);
}