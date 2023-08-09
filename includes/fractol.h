/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:36 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/09 20:05:10 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <libc.h>
# include <math.h>

# define MAX_ITERATIONS 100
# define WIDTH 1080
# define HEIGHT 1080

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_vars;

typedef struct s_range
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_range;

typedef struct s_complex
{
	double		re;
	double		im;
}	t_cmplx;

typedef enum e_color
{
	BLACK = 0x000000,
	RED = 0xFF0000,
	YELLOW = 0xFFFF00,
	WHITE = 0xFFFFFF,
}	t_color;

void	draw_mandelbrot(t_vars *img, t_range range);
void	draw_julia(t_vars *img, t_range range);
void	my_mlx_pixel_put(t_vars *data, int x, int y, int color);
t_cmplx	add_complex(t_cmplx a, t_cmplx b);
t_cmplx	sub_complex(t_cmplx a, t_cmplx b);
t_cmplx	mul_complex(t_cmplx a, t_cmplx b);
t_cmplx	div_complex(t_cmplx a, t_cmplx b);
double	complex_abs(t_cmplx z);
t_color	get_color(int iter);

#endif