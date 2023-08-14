/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kudoutomoya <kudoutomoya@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:42:58 by kudoutomoya       #+#    #+#             */
/*   Updated: 2023/08/13 18:40:30 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/libft.h"

static void	skip_space(const char **str)
{
	while (ft_isspace(**str))
		(*str)++;
}

static void	check_sign(const char **str, int *sign)
{
	if (**str == '-')
	{
		*sign *= -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
}

static double	parse_integer_part(const char **str)
{
	double	num;
	double	over_div;
	double	over_mod;

	num = 0.0;
	over_div = DBL_MAX / 10;
	over_mod = DBL_MAX - over_div * 10;
	while (ft_isdigit(**str))
	{
		if (over_div < num || (over_div == num && over_mod < **str - '0'))
			put_error_exit("Error: This number overflows.\n");
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num);
}

static double	parse_decimal_part(const char **str)
{
	double	num;
	double	decimal_place;

	num = 0.0;
	decimal_place = 0.1;
	while (ft_isdigit(**str))
	{
		num += (**str - '0') * decimal_place;
		decimal_place /= 10;
		(*str)++;
	}
	return (num);
}

double	ft_atof(const char *str)
{
	double	num;
	int		sign;

	num = 0.0;
	sign = 1;
	skip_space(&str);
	check_sign(&str, &sign);
	if (*str == '-' || *str == '+')
		put_error_exit("Error: Signs must not be consecutive.\n");
	else if (!ft_isdigit(*str))
		put_error_exit("Error: There is a character before the integer part.\n");
	num += parse_integer_part(&str);
	if (*str == '.')
	{
		str++;
		num += parse_decimal_part(&str);
		if (*str != '\0')
			put_error_exit("Error: Non-numeric character in decimal part.\n");
	}
	else if (*str != '\0')
		put_error_exit("Error: Non-numeric character in integer part.\n");
	return (sign * num);
}
