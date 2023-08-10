/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:15:53 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/09 20:15:08 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_mandelbrot(t_vars *data, t_range range)
{
	t_cmplx	c;
	t_cmplx	z;
	t_color	color;
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = range.x_min + x * (range.x_max - range.x_min) / WIDTH - 0.285;
			c.im = range.y_min + y * (range.y_max - range.y_min) / HEIGHT;
			z.re = 0;
			z.im = 0;
			i = 0;
			while (i < MAX_ITERATIONS)
			{
				z = add_complex(mul_complex(z, z), c);
				if (complex_abs(z) > 2.0)
					break ;
				i++;
			}
			color = get_color(i);
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
}
