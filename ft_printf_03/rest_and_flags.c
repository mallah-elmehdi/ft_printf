/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_and_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:36:13 by emallah           #+#    #+#             */
/*   Updated: 2019/12/09 21:10:59 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*rest_and_flags(va_list go, const char **s)
{
	int		j;

	j = 0;
	if (is_point(s))
		return (rest_output_1(go, s, j));
	return (rest_output_2(go, s, j));
}

char	*rest_output_1(va_list go, const char **s, int j)
{
	int		c1;
	int		c2;
	int		i;
	char	*p;

	i = 0;
	while (**s == '-' && (*s = *s + 1))
		j = 1;
	if ((!(c1 = 0)) && **s == '*' && ++i)
		c1 = va_arg(go, int);
	while (s[0][i] >= '0' && s[0][i] <= '9')
		c1 = (c1 * 10) + (s[0][i++] - 48);
	if (c1 < 0 && (j = 1))
		c1 = -c1;
	if ((!(c2 = 0)) && ++i && s[0][i] == '*')
		c2 = va_arg(go, int);
	while (s[0][i] >= '0' && s[0][i] <= '9')
		c2 = (c2 * 10) + (s[0][i++] - 48);
	if (c2 < 0)
		c2 = 0;
	while (is_flag(**s))
		*s = *s + 1;
	p = ft_convertion(go, **s);
	return (case1(&p, c1, c2, j));
}

char	*case1(char **p, int c1, int c2, int j)
{
	long	a;
	int		i;
	char	*d;

	if ((!(i = 0)) && p[0][0] == '0')
		p[0][0] = '\0';
	else if ((a = c1) >= 0 && p[0][0] == '-')
		return (neg_case1(p, c1, c2, j));
	if (len(*p) >= c1 && len(*p) >= c2)
		return (*p);
	if (c2 > c1)
		a = c2;
	if (!(d = (char*)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	a = 0;
	while (a < (c1 - c2) && a < (c1 - len(*p)))
		d[a++] = 32;
	while (a < (c1 - len(*p)) || a < (c2 - len(*p)))
:		d[a++] = 48;
	while (p[0][i] != '\0')
		d[a++] = p[0][i++];
	d[a] = '\0';
	if (j == 1 && ft_free(*p))
		d = rev(d);
	return (d);
}

char	*neg_case1(char **p, int c1, int c2, int j)
{
	long	a;
	int		i;
	int		b;
	char	*d;

	a = c1;
	if ((i = 1) && p[0][0] == '0')
		p[0][0] = '\0';
	if (len(*p) > c1 && len(*p) > c2)
		return (*p);
	if ((!(b = 0)) && c2 > c1)
		a = c2 + 1;
	if (!(d = (char*)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	while (b < (c1 - c2 - 1) && b < (c1 - len(*p) - 1))
		d[b++] = 32;
	d[b++] = '-';
	while (b < (a - len(*p) + 1) && (!(d[a] = '\0')))
		d[b++] = 48;
	while (p[0][i] != '\0')
		d[b++] = p[0][i++];
	if (j == 1)
		d = rev(d);
	ft_free(*p);
	return (d);
}

char	*rest_output_2(va_list go, const char **s, int j)
{
	int		c1;
	int		i;
	char	*p;

	i = 0;
	while (**s == '-' && (*s = *s + 1))
		j = 1;
	while (**s == '0' && (*s = *s + 1))
		j = 16;
	if ((!(c1 = 0)) && **s == '*' && ++i)
		c1 = va_arg(go, int);
	while (s[0][i] >= '0' && s[0][i] <= '9')
		c1 = (c1 * 10) + (s[0][i++] - 48);
	if (c1 < 0 && (j = 1))
		c1 = -c1;
	while (is_flag(**s))
		*s = *s + 1;
	p = ft_convertion(go, **s);
	return (case2(&p, c1, j));
}

char	*case2(char **p, long c1, int j)
{
	int		a;
	int		i;
	int		o;
	char	*d;

	i = 0;
	if ((!(a = 0)) && p[0][0] == '-')
		return (neg_case2(p, c1, j));
	if ((!(o = 0)) && len(*p) >= c1)
		return (*p);
	if (!(d = (char*)malloc(sizeof(char) * (c1 + 1))))
		return (NULL);
	if (j == 1 && (o = 1))
		j = 0;
	while (a < (c1 - len(*p)))
		d[a++] = 32 + j;
	while (p[0][i] != '\0')
		d[a++] = p[0][i++];
	d[a] = '\0';
	if (o == 1)
		d = rev(d);
	ft_free(*p);
	return (d);
}

char	*neg_case2(char **p, long c1, int j)
{
	int		a;
	int		i;
	int		o;
	char	*d;

	i = 0;
	a = 0;
	if ((!(o = 0)) && len(*p) > c1)
		return (*p);
	if (!(d = (char*)malloc(sizeof(char) * (c1 + 2))))
		return (NULL);
	if (j == 1 && (o = 1))
		j = 0;
	if (j == 16 && (p[0][0] = '0'))
		d[a++] = '-';
	while (a < (c1 - len(*p)))
		d[a++] = 32 + j;
	while (p[0][i] != '\0')
		d[a++] = p[0][i++];
	d[a] = '\0';
	if (o == 1)
		d = rev(d);
	ft_free(*p);
	return (d);
}

char	*rev(char *d)
{
	char	*rev;
	int		i;
	int		a;

	a = 0;
	i = 0;
	if (!(rev = (char*)malloc(sizeof(char) * (len(d) + 1))))
		return (NULL);
	while (d[a] == 32)
		a++;
	while (d[a] != '\0')
		rev[i++] = d[a++];
	a = 0;
	while (d[a] == 32)
		rev[i++] = d[a++];
	rev[i] = '\0';
	ft_free(d);
	return (rev);
}
