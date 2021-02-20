/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_convertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:53:08 by emallah           #+#    #+#             */
/*   Updated: 2019/11/28 23:15:29 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_here.h"

int		ft_putunc(long n, char c)
{
	char	*d;
	int		i;

	i = 0;
	if (c == 'c')
	{
		c = n;
		return (write (1, &c, 1));
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
	return (ft_strrev(d, c));
}

int		ft_putstr(char const *s)
{
	int i;

	if (s)
	{
		i = ft_strlen(s);
		write(1, s, i);
		ft_free((char *)s);
		return (i);
	}
	else
		return (write(1 ,"(null)", 6));

}

int		dtoxp(unsigned long s, char c)
{
	char	*d;
	int		i;
	int		o;

	o = 0;
	i = 0;
	d = (char*)malloc(sizeof(char) * 21);
	if (c == 'X')
		o = -32;
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
	return (ft_strrev(d, c));
}

int		ft_strrev(char *s, char c)
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
	ft_free(s);
	return (ft_putstr(hold));
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		i++;
	}
	return (i);
}
