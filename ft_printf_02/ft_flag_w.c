/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:22:13 by emallah           #+#    #+#             */
/*   Updated: 2019/12/03 18:33:12 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_flag_w(const char **s, int i, int j, va_list go)
{
	int a;
	long count;
	long count2;
	char *d;

	a = 0;
	if ((!(count = 0)) && (!(count2 = 0)) && **s == '*' && ++a)
		count = va_arg(go, long);
	while (s[0][a] >= '0' && s[0][a] <= '9')
		count = (count * 10) + (s[0][a++] - 48);
	if (count > 2147483647)
		count = 0;
	if (s[0][a++] == '.' && (!(i = 0)))
	{
		if (((count2 = counter(&s[0][a], go)) >= count) && count && (i = 16))
			count = count2;
		if (count2 < count && (d = flag_p(count, count2, j)))
			return (d);
	}
	if (!(d = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	d[count] = '\0';
	while (count)
		d[--count] = 32 + i;
	return (d);
}

char	*flag_p(long c, long c2, int j)
{
	int i;
	char *s;

	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * (c + 1))))
		return (NULL);
	if (j == 1)
	{
		while (i < c2)
			s[i++] = 48;
		while (i < c)
			s[i++] = 32;
	}
	else
	{
		while ((c - c2) > i)
			s[i++] = 32;
		while (i < c)
			s[i++] = 48;
	}
	return (s);
}

long	counter(const char *s, va_list go)
{
	int a;
	int count2;

	a = 0;
	count2 = 0;
	if (*s == '*')
		return (va_arg(go, long));
	while (s[a] >= '0' && s[a] <= '9')
		count2 = (count2 * 10) + (s[a++] - 48);
	return (count2);
}
