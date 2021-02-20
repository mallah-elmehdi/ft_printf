/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:55:15 by emallah           #+#    #+#             */
/*   Updated: 2019/12/04 18:55:17 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_output(char c, char **d, int j, va_list go)
{
	int i;
	int a;
	char *s;

	s = ft_convertion(go, c);
	if (c == 's' && j == 3)
		return (s_conv(d, &s));
	if (s[0] == '0' && j == 3)
			s[0] = '\0';
	if ((!(i = 0)) && (!(a = 0))  && ft_strlen(s) >= ft_strlen(*d))
		return (s);
	else
	{
		if (s[0] == '-' && j == 2 && (*d = change(d)))
			s[0] = '0';
		if (s[0] == '-' && j == 3 && (*d = change1(d)))
			s[0] = '0';
		if ((a = ft_strlen(s)) && j != 1)
			a = last_0(d, j);
		i = ft_strlen(s);
		while (i)
			d[0][--a] = s[--i];
	}
	return (*d);
}

int		last_0(char **s, int j)
{
	int i;

	i = 0;
	while (j && s[0][i] != '\0')
	{
		while (s[0][i] == '0')
		{
			i++;
			if (s[0][i] != '0')
				return (i);
		}
		i++;
	}
	return (ft_strlen(*s));
}

char	*change(char **d)
{
	int i;

	i = 0;
	while (d[0][i] != '\0')
	{
		if (d[0][i] == '0')
		{
			d[0][i] = '-';
			break ;
		}
		i++;
	}
	return (*d);
}

char     *change1(char **d)
{
	char *s;
	int i;
	int j;
	int a;

	if ((!(i = 0)) && (!(j = 0)))
		a = 0;
	while (d[0][i] == ' ' && d[0][i] != '\0')
	{
		if (d[0][++i] == '0')
		{
			d[0][--i] = '-';
			return (*d);
		}
	}
	if ((!(i = 0)) && !(s = (char *)malloc(sizeof(char) * (ft_strlen(*d) + 2))))
		return (NULL);
	while (d[0][i] != '\0')
	{
		if (d[0][i] == '0' && a == 0 && (s[j++] = '-'))
			a = 1;
		s[j++] = d[0][i++];
	}
	return (s);
}
