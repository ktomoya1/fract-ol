/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:38:58 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/06 20:07:43 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	draw_mandelbrot(t_data *img, double x_min, double x_max,
//         double y_min, double y_max, int max_iter)
// {
//     int		x;
//     int		y;
//     double	c_re;
//     double	c_im;
//     double	z_re;
//     double	z_im;
//     double	z_re_new;
//     double	z_im_new;
//     int		iter;
//     int		color;

//     for (y = 0; y < img->height; y++)
//     {
//         for (x = 0; x < img->width; x++)
//         {
//             c_re = x_min + (x * (x_max - x_min) / img->width);
//             c_im = y_min + (y * (y_max - y_min) / img->height);
//             z_re = 0;
//             z_im = 0;
//             iter = 0;
//             while (z_re * z_re + z_im * z_im <= 4 && iter < max_iter)
//             {
//                 z_re_new = z_re * z_re - z_im * z_im + c_re;
//                 z_im_new = 2 * z_re * z_im + c_im;
//                 z_re = z_re_new;
//                 z_im = z_im_new;
//                 iter++;
//             }
//             color = (iter == max_iter) ? 0x000000 : 0xFFFFFF;
//             my_mlx_pixel_put(img, x, y, color);
//         }
//     }
// }

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	// int		x;
	// int		y;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
    img.height = 1080;
    img.width = 1920;
    draw_mandelbrot(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
