/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot_set.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:15:53 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/05 18:39:32 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	draw_mandelbrot_set(t_data *img)
{
	t_cx	c;
	t_cx	z;
	int			x;
	int			y;
	int			i;

	// copilot:
	// 1.描画する領域の範囲を指定する
	// x_minからx_maxまでの範囲とy_minからy_maxまでの範囲を指定する
	// x_min = -2.0, x_max = 2.0, y_min = -2.0, y_max = 2.0
	x = 0;
	y = 0;
	i = 0;
	img->x_min = -2.0;
	img->x_max = 2.0;
	img->y_min = -2.0;
	img->y_max = 2.0;

	while (y < img->height)
	{
		x = 0;
		// 2.各点に対して複素数cを割り当てる
		// 画像の幅と高さを使用して、各点に対応する複素数cを計算する
		while (x < img->width)
		{
			c.re = img->x_min + x * (img->x_max - img->x_min) / img->width;
			c.im = img->y_min + y * (img->y_max - img->y_min) / img->height;
			// 3.zを0に設定する
			z.re = 0;
			z.im = 0;
			// 4.複素数zがマンデルブロ集合に属するかどうかを判定する
			// z = z^2 + c を繰り返し適用し、zの絶対値が2を超えたら、その点はマンデルブロ集合に属さないと判定する
			while (i < MAX_ITERATIONS)
			{
				z = add_complex(mul_complex(z, z), c);
				if (complex_abs(z) > 2.0)
					break ;
			}
			// 5.zがマンデルブロ集合に属する場合は、黒色、属さない場合は白色で点を描画する
			if (i == MAX_ITERATIONS)
				my_mlx_pixel_put(img, x, y, 0x000000);
			else
				my_mlx_pixel_put(img, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}
