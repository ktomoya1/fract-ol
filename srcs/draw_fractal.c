/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:27:47 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/14 15:41:37 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_color	get_color(int iter)
{
	double	ratio;

	if (iter == MAX_ITERATIONS)
		return (WHITE);
	ratio = (double)iter / MAX_ITERATIONS;
	if (ratio < 0.25)
		return (iter * 0x090000);
	else if (ratio < 0.5)
		return (RED);
	else if (ratio < 0.75)
		return (YELLOW);
	else
		return (WHITE);
}

static int	count_iterations(t_cmplx z, t_cmplx c)
{
	int	iter;

	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		z = add_complex(mul_complex(z, z), c);
		if (complex_abs(z) > 2.0)
			break ;
		iter++;
	}
	return (iter);
}

static void	draw_mandelbrot(t_vars *d)
{
	t_cmplx	c;
	t_cmplx	z;
	int		x;
	int		y;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = d->x_min + x * (d->x_max - d->x_min) / WIDTH - 0.285;
			c.im = d->y_min + y * (d->y_max - d->y_min) / HEIGHT;
			z.re = 0;
			z.im = 0;
			iter = count_iterations(z, c);
			my_mlx_pixel_put(d, x, y, get_color(iter));
			x++;
		}
		y++;
	}
}

static void	draw_julia(t_vars *d)
{
	t_cmplx	z;
	int		x;
	int		y;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.re = d->x_min + x * (d->x_max - d->x_min) / WIDTH;
			z.im = d->y_min + y * (d->y_max - d->y_min) / HEIGHT;
			iter = count_iterations(z, d->c);
			my_mlx_pixel_put(d, x, y, get_color(iter));
			x++;
		}
		y++;
	}
}

void	draw_fractal(t_vars *data)
{
	if (data->type == MANDELBROT)
		draw_mandelbrot(data);
	else if (data->type == JULIA)
		draw_julia(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
