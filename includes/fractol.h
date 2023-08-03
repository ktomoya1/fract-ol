/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:36 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/03 19:35:30 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <libc.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_data;

typedef struct s_complex
{
	double		re;
	double		im;
}	t_complex;

t_complex	add_complex(t_complex a, t_complex b);
t_complex	sub_complex(t_complex a, t_complex b);
t_complex	mul_complex(t_complex a, t_complex b);
t_complex	div_complex(t_complex a, t_complex b);

#endif