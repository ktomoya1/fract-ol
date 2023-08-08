/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:15:53 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/08 18:16:17 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_mandelbrot(t_data *img)
{
	t_cmplx	c;
	t_cmplx	z;
	t_color	color;
	int		x;
	int		y;
	int		i;

	y = 0;
	img->x_min = -2.0;
	img->x_max = 2.0;
	img->y_min = -2.0;
	img->y_max = 2.0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = img->x_min + x * (img->x_max - img->x_min) / WIDTH - 0.285;
			c.im = img->y_min + y * (img->y_max - img->y_min) / HEIGHT;
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
			my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
}
