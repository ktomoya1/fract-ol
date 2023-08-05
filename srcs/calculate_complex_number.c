/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_complex_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:25:44 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/05 18:38:51 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_cx	add_complex(t_cx a, t_cx b)
{
	t_cx	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_cx	sub_complex(t_cx a, t_cx b)
{
	t_cx	result;

	result.re = a.re - b.re;
	result.im = a.im - b.im;
	return (result);
}

t_cx	mul_complex(t_cx a, t_cx b)
{
	t_cx	result;

	result.re = a.re * b.re - a.im * b.im;
	result.im = a.re * b.im + a.im * b.re;
	return (result);
}

t_cx	div_complex(t_cx a, t_cx b)
{
	t_cx	result;
	double	denominator;

	denominator = b.re * b.re + b.im * b.im;
	result.re = (a.re * b.re + a.im * b.im) / denominator;
	result.im = (a.im * b.re - a.re * b.im) / denominator;
	return (result);
}
