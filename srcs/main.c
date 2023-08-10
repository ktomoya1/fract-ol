/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:38:58 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/10 20:16:38 by ktomoya          ###   ########.fr       */
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
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	exit_on_close(t_vars *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	mouse_scroll(int button, int x, int y, t_vars *data)
{
	double	center_x;
	double	center_y;

	(void)x;
	(void)y;
	if (button == 4)
	{
		// 拡大率を調整する
		// 中心座標を計算する
		center_x = data->x_min + (data->x_max - data->x_min) / 2;
		center_y = data->y_min + (data->y_max - data->y_min) / 2;
		// 中心座標を基準に、画像を拡大する(描画範囲の更新)
		data->x_min = center_x - (center_x - data->x_min) * 1.1;
		data->x_max = center_x + (data->x_max - center_x) * 1.1;
		data->y_min = center_y - (center_y - data->y_min) * 1.1;
		data->y_max = center_y + (data->y_max - center_y) * 1.1;
		// 拡大した画像を再描画する
		draw_mandelbrot(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	else if (button == 5)
	{
		center_x = data->x_min + (data->x_max - data->x_min) / 2;
		center_y = data->y_min + (data->y_max - data->y_min) / 2;
		data->x_min = center_x - (center_x - data->x_min) / 1.1;
		data->x_max = center_x + (data->x_max - center_x) / 1.1;
		data->y_min = center_y - (center_y - data->y_min) / 1.1;
		data->y_max = center_y + (data->y_max - center_y) / 1.1;
		draw_mandelbrot(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}

// int	key_press(int keycode, t_vars *param)
// {
//     (void)param;
//     if (keycode == 53) // 53 is the keycode for ESC key
//         printf("ESC key is pressed!\n");
// 	else
// 		printf("keycode: %d\n", keycode);
//     return (0);
// }

int	main(void)
{
	t_vars	data;

	data.x_min = -2.0;
	data.x_max = 2.0;
	data.y_min = -2.0;
	data.y_max = 2.0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "fractol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
			&data.endian);
	draw_mandelbrot(&data);
	// draw_julia(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 4, 0, mouse_scroll, &data);
	mlx_key_hook(data.win, esc_close, &data);
	mlx_hook(data.win, 17, 0, exit_on_close, &data);
	mlx_loop(data.mlx);
}
