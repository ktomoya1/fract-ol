/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:27:47 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/10 19:10:22 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

// cの実部と虚部は外部から受け取る:Todo
void	draw_julia(t_vars *data)
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
			z.re = data->x_min + x * (data->x_max - data->x_min) / WIDTH;
			z.im = data->y_min + y * (data->y_max - data->y_min) / HEIGHT;
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
