/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:09:36 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/08 18:17:21 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_color	get_color(int iter)
{
	double	ratio;

	if (iter == MAX_ITERATIONS)
		return (WHITE);
	ratio = (double)iter / MAX_ITERATIONS;
	if (ratio < 0.25)
		return (BLACK);
	else if (ratio < 0.5)
		return (RED);
	else if (ratio < 0.75)
		return (YELLOW);
	else
		return (WHITE);
}
