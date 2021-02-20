/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 20:16:06 by emallah           #+#    #+#             */
/*   Updated: 2019/11/29 16:28:37 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_here.h"

int	zs_flag(const char **d)
{
	int a;

	a = 0;
	while (**d >= '0' && **d <= '9')
	{
		a = (a * 10) + (**d - 48);
		*d = *d + 1;
	}
	return (a);
}

int		strout(char *s, char c, char **d, int i)
{
	char *p;
	if (c == 's')
	{
		if (i == 0 && (ft_strlen(s) < ft_strlen(*d)))
			return (str_out(d, &s, (ft_strlen(*d) - ft_strlen(s)), 0));
		else if (i == 1 && (ft_strlen(s) < ft_strlen(*d)))
			return (str_out_rev(d, s));
		return (ft_putstr(s));
	}
	p = ft_strrevx(s, c);
	if (i == 0 && (ft_strlen(p) < ft_strlen(*d)))
		return (str_out(d, &p, (ft_strlen(*d) - ft_strlen(p)), 0));
	else if (i == 1 && (ft_strlen(p) < ft_strlen(*d)))
		return (str_out_rev(d, p));
	return (ft_putstr(p));
}

int		out_int(long n, char c, char **d, int i)
{
	char *s;

	s = putd(n, c);
	if (i == 0 && (ft_strlen(s) < ft_strlen(*d)))
		return (str_out(d, &s, (ft_strlen(*d) - ft_strlen(s)), 1));
	else if (i == 1 && (ft_strlen(s) < ft_strlen(*d)))
		return (str_out_rev(d, s));
	return (ft_putstr(s));
}

int		str_out_rev(char **d, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		d[0][i]= s[i];
		i++;
	}
	i = ft_strlen(*d);
	write (1, *d, i);
	ft_free(*d);
	return (i);
}

int		str_out(char **d, char **s, int max, int a)
{
	int i;

	i = 0;
	while (d[0][max] != '\0')
	{
		d[0][max] = s[0][i];
		i++;
		max++;
	}
	i = ft_strlen(*d);
	write (1, *d, i);
	ft_free(*d);
	if (a)
		ft_free(*s);
	return (i);
}

char	*putd(long n, char c)
{
	char	*d;
	int		i;

	i = 0;
	if (c == 'c')
	{
		d = (char *)malloc(sizeof(char) * 2);
		d[0] = n;
		return (d);
	}
	else
	{
		d = (char *)malloc(sizeof(char) * 21);
		if (n < 0 && ((n = -n) > 0))
			d[i++] = '-';
		while (n)
		{
			d[i] = (n % 10) + 48;
			n = n / 10;
			i++;
		}
		d[i] = '\0';
	}
	return (str_rev(&d));
}

char 	*str_rev(char **s)
{
	char	*hold;
	int		j;
	int		i;

	hold = (char*)malloc(sizeof(char) * ft_strlen(*s) + 1);
	j = 0;
	i = ft_strlen(*s) - 1;
	while (i >= 0)
		hold[j++] = s[0][i--];
	hold[j] = '\0';
	ft_free(*s);
	return (hold);
}

int		out_uint(unsigned long s, char c, char **p, int m)
{
	char	*d;
	int		i;
	int		o;

	o = 0;
	i = 0;
	d = (char*)malloc(sizeof(char) * 21);
	if (c == 'X')
		o = -32;
	if (s == 0)
		d[i++] = '0';
	while (s)
	{
		if ((s % 16) >= 10 && (s % 16) <= 15)
			d[i] = (s % 16) + o + 87;
		else
			d[i] = (s % 16) + 48;
		s = s / 16;
		i++;
	}
	d[i] = '\0';
	return (strout(d, c, p, m));
}

char	*ft_strrevx(char *s, char c)
{
	char	*hold;
	int		j;
	int		i;

	hold = (char*)malloc(sizeof(char) * ft_strlen(s) + 3);
	j = 0;
	i = ft_strlen(s) - 1;
	if (c == 'p')
	{
		hold[j++] = '0';
		hold[j++] = 'x';
	}
	while (i >= 0)
		hold[j++] = s[i--];
	hold[j] = '\0';
	return (hold);
}
