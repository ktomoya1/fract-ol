/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:36 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/08 16:24:25 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <libc.h>
# include <math.h>

# define MAX_ITERATIONS 100
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_data;

typedef struct s_complex
{
	double		re;
	double		im;
}	t_cmplx;

void	draw_mandelbrot(t_data *img);
void	draw_julia(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_cmplx	add_complex(t_cmplx a, t_cmplx b);
t_cmplx	sub_complex(t_cmplx a, t_cmplx b);
t_cmplx	mul_complex(t_cmplx a, t_cmplx b);
t_cmplx	div_complex(t_cmplx a, t_cmplx b);
double	complex_abs(t_cmplx z);

#endif