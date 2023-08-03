/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:21:36 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/03 15:24:53 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <libc.h>

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