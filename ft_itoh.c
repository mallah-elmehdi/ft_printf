/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:24:50 by emallah           #+#    #+#             */
/*   Updated: 2019/12/06 17:23:28 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		len_us(unsigned long n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i + 1);
}

char	*ft_itoh(unsigned long s, char c)
{
	char	*d;
	int		i;
	int		o;

	if ((!(o = 0)) && c == 'X')
		o = -32;
	if (((i = len_us(s)) && c == 'p'))
		i = i + 2;
	if (!(d = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	d[--i] = '\0';
	if ((d[0] = '0') && c == 'p')
	{
		if ((d[1] = 'x') && (s == 0))
			d[2] = '0';
	}
	while (s)
	{
		if ((s % 16) >= 10 && (s % 16) <= 15)
			d[--i] = (s % 16) + o + 87;
		else
			d[--i] = (s % 16) + 48;
		s = s / 16;
	}
	return (d);
}
