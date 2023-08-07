/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_complex_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:25:44 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/07 20:17:29 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_cmplx	add_complex(t_cmplx a, t_cmplx b)
{
	t_cmplx	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_cmplx	sub_complex(t_cmplx a, t_cmplx b)
{
	t_cmplx	result;

	result.re = a.re - b.re;
	result.im = a.im - b.im;
	return (result);
}

t_cmplx	mul_complex(t_cmplx a, t_cmplx b)
{
	t_cmplx	result;

	result.re = a.re * b.re - a.im * b.im;
	result.im = a.re * b.im + a.im * b.re;
	return (result);
}

t_cmplx	div_complex(t_cmplx a, t_cmplx b)
{
	t_cmplx	result;
	double	denominator;

	denominator = b.re * b.re + b.im * b.im;
	result.re = (a.re * b.re + a.im * b.im) / denominator;
	result.im = (a.im * b.re - a.re * b.im) / denominator;
	return (result);
}

double	complex_abs(t_cmplx z)
{
	double	real_squared;
	double	imag_squared;
	double	sum;

	real_squared = z.re * z.re;
	imag_squared = z.im * z.im;
	sum = real_squared + imag_squared;
	return (sqrt(sum));
}
