/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:13:55 by emallah           #+#    #+#             */
/*   Updated: 2019/12/03 20:12:19 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *ft_flags(va_list go, const char **s, char c)
{
	int j;
	int i;
	char *d;

	j = 0;
	while (c == '-' && (j = 1) && (*s = *s + 1))
		c = **s;
	if ((!(i = 0)))
	{
		while (c == '0' && (*s = *s + 1) && (c = **s) && (j = 2))
			i = 16;
	}
	if (is_point(s))
			j = 3;
	d = ft_flag_w(s, i, j, go);
	while (is_flag(**s))
		*s = *s + 1;
	return (ft_output(**s, &d, j, go));
}
