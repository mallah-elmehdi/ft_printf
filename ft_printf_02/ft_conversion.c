/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:52:24 by emallah           #+#    #+#             */
/*   Updated: 2019/12/03 14:14:53 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_convertion(va_list go, char c)
{
	char *d;

	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(go, int)));
	else if (c == 'c')
	{
		if (!(d = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		if ((d[0] = va_arg(go, int)) && (!(d[1] = '\0')))
			return (d);
	}
	else if (c == 'x' || c == 'X')
		return (ft_itoh(va_arg(go, unsigned int), c));
	else if (c == 'u')
		return (ft_itoa(va_arg(go, unsigned int)));
	else if (c == 'p')
		return (ft_itoh(va_arg(go, unsigned long), c));
	else if (c == 's')
	{
		if ((d = va_arg(go, char*)) == NULL)
				return("(null)");
		return (d);
	}
	return (NULL);
}
