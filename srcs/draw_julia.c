/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:27:47 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/09 20:16:00 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// cの実部と虚部は外部から受け取る:Todo
void	draw_julia(t_vars *data, t_range range)
{
	t_cmplx	c;
	t_cmplx	z;
	t_color	color;
	int		x;
	int		y;
	int		i;

	y = 0;
	c.re = -0.8;
	c.im = 0.156;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.re = range.x_min + x * (range.x_max - range.x_min) / WIDTH;
			z.im = range.y_min + y * (range.y_max - range.y_min) / HEIGHT;
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
