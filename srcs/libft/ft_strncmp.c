/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktomoya <ktomoya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:48:07 by ktomoya           #+#    #+#             */
/*   Updated: 2023/08/03 17:21:10 by ktomoya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				dif;
	unsigned char	*ls1;
	unsigned char	*ls2;

	dif = 0;
	ls1 = (unsigned char *)s1;
	ls2 = (unsigned char *)s2;
	while (n--)
	{
		dif = *ls1 - *ls2;
		if (dif != 0)
			return (dif);
		if (*ls1 == '\0')
			break ;
		ls1++;
		ls2++;
	}
	return (0);
}
