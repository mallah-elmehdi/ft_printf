/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:37:07 by emallah           #+#    #+#             */
/*   Updated: 2019/12/04 18:59:38 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putstr(va_list go, const char **s, char c)
{
	char *d;

	if (is_conv(c))
	{
		d = ft_convertion(go, c);
		return (write(1, d, ft_strlen(d)));
	}
	else if (is_flag(c))
	{
		d = ft_flags(go, s, c);
		return (write(1, d, ft_strlen(d)));
	}
	return (0);
}

char	*s_conv(char **d, char *s)
{
	int i;
	int j;
	int a;

	i = 0;
	j = 0;
	a = 0;
	while (d[0][i] != '\0')
	{
		while (d[0][i++] == ' ')
			a++;
		i--;
		while (d[0][i++] == '0')
			j++;
		i--;
		i++;
	}
	if (a <= j && j >= ft_strlen(s))
		return (s);
	else if (a <= j && j < ft_strlen(s) && (!(s[j] = '\0')))
		return (s);
	return (s);
}
