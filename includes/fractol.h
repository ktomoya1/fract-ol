/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:36 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/05 19:31:13 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <libc.h>

# define MAX_ITERATIONS 100

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_data;

typedef struct s_complex
{
	double		re;
	double		im;
}	t_cx;

void	draw_mandelbrot(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_cx	add_complex(t_cx a, t_cx b);
t_cx	sub_complex(t_cx a, t_cx b);
t_cx	mul_complex(t_cx a, t_cx b);
t_cx	div_complex(t_cx a, t_cx b);

#endif