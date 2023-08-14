/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kudoutomoya <kudoutomoya@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:54:54 by kudoutomoya       #+#    #+#             */
/*   Updated: 2023/08/13 10:25:13 by kudoutomoya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	esc_close(int keycode, t_vars *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	exit_on_close(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(EXIT_SUCCESS);
}

int	mouse_scroll(int button, int x, int y, t_vars *data)
{
	double	center_x;
	double	center_y;

	(void)x;
	(void)y;
	center_x = 0.0;
	center_y = 0.0;
	if (button == MOUSE_SCROLL_UP)
	{
		data->x_min = center_x - (center_x - data->x_min) * 1.1;
		data->x_max = center_x + (data->x_max - center_x) * 1.1;
		data->y_min = center_y - (center_y - data->y_min) * 1.1;
		data->y_max = center_y + (data->y_max - center_y) * 1.1;
		draw_fractal(data);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		data->x_min = center_x - (center_x - data->x_min) / 1.1;
		data->x_max = center_x + (data->x_max - center_x) / 1.1;
		data->y_min = center_y - (center_y - data->y_min) / 1.1;
		data->y_max = center_y + (data->y_max - center_y) / 1.1;
		draw_fractal(data);
	}
	return (0);
}
