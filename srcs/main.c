/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kudoutomoya <kudoutomoya@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:38:58 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/10 15:45:10 by kudoutomoya      ###   ########.fr       */
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
	if (keycode == 53)
		mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int exit_on_close(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

// int	mouse_scroll()

int	mouse_move(t_vars *data)
{
	printf("Mouse moved to (%d, %d)\n", data->x, data->y);
	return (0);
}

// int	key_press(int keycode, void *param)
// {
//     (void)param;
//     if (keycode == 53) // 53 is the keycode for ESC key
//         printf("ESC key is pressed!\n");
//     return (0);
// }

int	main(void)
{
	t_vars	data;
	t_range	range;

	range.x_min = -2.0;
	range.x_max = 2.0;
	range.y_min = -2.0;
	range.y_max = 2.0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fractol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
			&data.endian);
	// draw_mandelbrot(&data, range);
	draw_julia(&data, range);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	// mlx_mouse_hook(data.win, mouse_scroll, &data);
	mlx_mouse_move(data.win, mouse_move, &data);
	mlx_key_hook(data.win, esc_close, &data);
	mlx_hook(data.win, 17, 0, exit_on_close, &data);
	
	// mlx_hook(mlx_win, 33, 1L << 0, close_window(mlx_key_hook(mlx_win, key_press, NULL), NULL);
	mlx_loop(data.mlx);
}
