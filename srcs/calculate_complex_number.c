/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_complex_number.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:25:44 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/03 15:46:29 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	add_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re + b.re;
	result.im = a.im + b.im;
	return (result);
}

t_complex	sub_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re - b.re;
	result.im = a.im - b.im;
	return (result);
}

t_complex	mul_complex(t_complex a, t_complex b)
{
	t_complex	result;

	result.re = a.re * b.re - a.im * b.im;
	result.im = a.re * b.im + a.im * b.re;
	return (result);
}

t_complex	div_complex(t_complex a, t_complex b)
{
	t_complex	result;
	double		denominator;

	denominator = b.re * b.re + b.im * b.im;
	result.re = (a.re * b.re + a.im * b.im) / denominator;
	result.im = (a.im * b.re - a.re * b.im) / denominator;
	return (result);
}
