/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 16:42:02 by emallah           #+#    #+#             */
/*   Updated: 2019/12/03 14:19:01 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		len_s(long n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (2);
	if (n < 0 && ((n = -n) > 0))
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char			*ft_itoa(long a)
{
	char	*s;
	int		count;

	count = len_s(a);
	if (!(s = (char*)malloc(sizeof(char) * count)))
		return (NULL);
	if (a < 0 && ((a = -a) > 0))
		s[0] = '-';
	s[--count] = '\0';
	if (a == 0)
		s[--count] = '0';
	while (a)
	{
		s[--count] = (a % 10) + 48;
		a = a / 10;
	}
	return (s);
}
