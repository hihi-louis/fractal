/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:27:43 by tripham           #+#    #+#             */
/*   Updated: 2025/02/22 15:10:39 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../library/libft/libft.h"
# include "../library/ft_printf/ft_printf.h"
# include "../library/MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <string.h>

# define WIDTH 800
# define HEIGHT 800

typedef enum e_set_type
{
	MANDELBROT,
	JULIA
}	t_set_type;

typedef struct s_complex
{
	double		x;
	double		y;
}	t_complex;

typedef struct s_range
{
	double	min;
	double	max;
	double	delta;
}	t_range;

typedef struct s_color
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
	uint32_t	alpha;
	uint32_t	color;
}	t_color;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	char		*set;
	t_complex	julia_c;
	t_range		real;
	t_range		imag;
	uint32_t	max_iter;
	uint32_t	iter;
	double		change_rate;
	t_complex	z;
	t_complex	c;
	t_complex	pixel;
	t_color		get;
	int32_t		pixel_x;
	int32_t		pixel_y;
	t_set_type	type;
}	t_fractol;

// Initialization
void		initialize_fractol(t_fractol *fractol, char **argv);
void		view_points(t_fractol *fractol);
void		initialize_julia(t_fractol *fractol, char **argv);
// color gereration
void		generate_color(t_fractol *fractol);
uint32_t	get_pixel(uint32_t red, uint32_t green, uint32_t blue, uint32_t a);
// Rendering
void		rendering(void *param);
void		convert_pixel_to_complex(double *r, double *i, t_fractol *fractol);
void		amount_of_escape(t_fractol *fractol);
// Hook
void		fractol_ctrl(mlx_key_data_t keydata, void *param);
void		fractol_arrow(void *param);
void		fractol_scroll(double xdelta, double ydelta, void *param);

// Fractal sets
void		mandelbrot(uint32_t x, uint32_t y, t_fractol *fractol);
void		julia(uint32_t x, uint32_t y, t_fractol *fractol);

// Log
int			fractol_error(char *str);
int			fractol_guide(void);

// check validation
int			check_validation_arg(int argc, char **argv);
int			check_validation_extra_args(int argc, char **argv);
int			check_float(char *str);

#endif