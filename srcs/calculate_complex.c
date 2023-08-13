/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_complex_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kudoutomoya <kudoutomoya@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:25:44 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/13 08:50:24 by kudoutomoya      ###   ########.fr       */
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

t_cmplx	mul_complex(t_cmplx a, t_cmplx b)
{
	t_cmplx	result;

	result.re = a.re * b.re - a.im * b.im;
	result.im = a.re * b.im + a.im * b.re;
	return (result);
}

double	complex_abs(t_cmplx z)
{
	return (sqrt(z.re * z.re + z.im * z.im));
}
