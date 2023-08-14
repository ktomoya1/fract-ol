/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:54:54 by kudoutomoya       #+#    #+#             */
/*   Updated: 2023/08/14 18:19:25 by ktomoya          ###   ########.fr       */
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
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
	{
		data->x_min = data->x_min * 1.1;
		data->x_max = data->x_max * 1.1;
		data->y_min = data->y_min * 1.1;
		data->y_max = data->y_max * 1.1;
		draw_fractal(data);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		data->x_min = data->x_min / 1.1;
		data->x_max = data->x_max / 1.1;
		data->y_min = data->y_min / 1.1;
		data->y_max = data->y_max / 1.1;
		draw_fractal(data);
	}
	return (0);
}
