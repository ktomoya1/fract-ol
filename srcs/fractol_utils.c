/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kudoutomoya <kudoutomoya@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:09:36 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/13 09:56:33 by kudoutomoya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/libft.h"

int	put_error_exit(char *str)
{
	ft_putstr_fd(str, STD_ERROR);
	exit(EXIT_FAILURE);
}

bool	is_str_equal(const char *s1, const char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	return (!ft_strncmp(s1, s2, ft_strlen(s1)));
}
