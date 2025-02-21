/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:27:43 by tripham           #+#    #+#             */
/*   Updated: 2025/02/21 05:02:05 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../library/libft/libft.h"
# include "../library/ft_printf/ft_printf.h"
# include "../library/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <string.h>

# define WIDTH 1500
# define HEIGHT 1500

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct s_complex
{
	double		x;
	double		y;
}	t_complex;

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
	uint32_t	color;
}	t_color;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		*set;
	int			max_iter;
	int			iter;
	double		move;
	t_complex	z;
	t_complex	c;
	t_complex	min;
	t_complex	max;
	t_color		pixel;
}	t_fractol;

// Guidiance
void	input_guide(void);
void	error_output(char *message_error);
int		arg_guide(char *message_error);

// Parsing
int	check_validation_arg(int argc, char **argv);

// Initialization
void	initialize_fractol(t_fractol *fractol, char **argv);

// color gereration
void	generate_color(t_fractol *fractol, int inter, double move);

// Rendering
void	rendering(t_fractol *fractol);
void	convert_pixel_to_complex(t_fractol *fractol, int x, int y , t_complex *c);

// Events
void	fractol_ctrl(mlx_key_data_t keydata, void *param);
void	fractol_zoom(double xdelta, double ydelta, void *param);
void	fractol_shift(void *param);


# endif