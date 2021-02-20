/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:37:07 by emallah           #+#    #+#             */
/*   Updated: 2019/12/13 21:27:15 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putstr(va_list go, const char **s, int c)
{
	char	*d;
	int		i;
	int		a;
	va_list	ok;

	va_copy(ok, go);
	i = 0;
	a = help(ok, s);
	if (is_conv(c) && (!(d = ft_convertion(go, c))))
		return (-1);
	else if (is_flag(c) && (!(d = ft_flags(go, s))))
		return (-1);
	if (**s == 'c' && (!(c = 0)) && a != 32)
	{
		while (d[c] == 32 && d[c] != '\0')
			c++;
		if (len(d) == c && ++i && a >= 0)
			c = -1;
	}
	i = i + write(1, d, len(d));
	if (c == -1)
		write(1, "\0", 1);
	ft_free(&d);
	return (i);
}

int		help(va_list ok, const char **s)
{
	int a;
	int j;

	j = 0;
	a = 0;
	while (s[0][a] == '-' && (j = -1))
		a++;
	if (s[0][a] == '*')
		j = va_arg(ok, int);
	while (is_flag(s[0][a]))
		a++;
	if (s[0][a] == 'c' && (a = va_arg(ok, int)) >= 0)
	{
		if (a == 32)
			j = 32;
	}
	return (j);
}
