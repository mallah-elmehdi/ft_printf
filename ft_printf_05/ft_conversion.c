/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:52:24 by emallah           #+#    #+#             */
/*   Updated: 2019/12/11 14:33:04 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_convertion(va_list go, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(go, int)));
	else if (c == 'c')
		return (ft_char(va_arg(go, int)));
	else if (c == 'x' || c == 'X')
		return (ft_itoh(va_arg(go, unsigned int), c));
	else if (c == 'u')
		return (ft_itoa(va_arg(go, unsigned int)));
	else if (c == 'p')
		return (ft_itoh(va_arg(go, unsigned long), c));
	else if (c == 's')
		return (ft_str(va_arg(go, char *)));
	return (ft_char('%'));
}

char	*ft_str(char *s)
{
	char	*d;
	int		i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	if (!(d = (char*)malloc(sizeof(char) * (len(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_char(int a)
{
	char	*d;

	if (!(d = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	d[0] = a;
	d[1] = '\0';
	return (d);
}
