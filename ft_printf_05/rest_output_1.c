/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_output_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:42:08 by emallah           #+#    #+#             */
/*   Updated: 2019/12/11 16:57:40 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*rest_output_1(va_list go, const char **s, int j, int i)
{
	int		c1;
	int		c2;
	char	*p;

	while (**s == '-' && (*s = *s + 1))
		j = 1;
	while (**s == '0' && (j = 16))
		*s = *s + 1;
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
	while (is_flag(**s) && (!(i = 0)))
		*s = *s + 1;
	p = ft_convertion(go, **s);
	if (c2 < 0 || (**s == 'c' && *p == '\0' && --c1 >= 0))
		return (case2(&p, c1, j));
	return (case1(&p, c1, c2, j));
}

char	*case1(char **p, int c1, int c2, int j)
{
	int		a;
	int		i;
	char	*d;

	if (p[0][0] == '0' && p[0][1] == 'x' && p[0][2] == '0' && len(*p) == 3)
		p[0][2] = '\0';
	if ((!(i = 0)) && p[0][1] != 'x' && p[0][0] == '0' && c2 == 0)
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
		d[a++] = 48;
	while (p[0][i] != '\0')
		d[a++] = p[0][i++];
	d[a] = '\0';
	if (j == 1 && ft_free(p))
		d = rev(d);
	return (d);
}

char	*neg_case1(char **p, int c1, int c2, int j)
{
	int		a;
	int		i;
	int		b;
	char	*d;

	a = c1;
	if (p[0][0] == '0' && p[0][1] == 'x' && p[0][2] == '0' && len(*p) == 3)
		p[0][2] = '\0';
	if ((i = 1) && p[0][1] != 'x' && p[0][0] == '0' && c2 == 0)
		p[0][0] = '\0';
	if (len(*p) > c1 && len(*p) > c2)
		return (*p);
	if ((!(b = 0)) && c2 >= c1)
		a = c2 + 1;
	if (!(d = (char*)malloc(sizeof(char) * (a + 1))))
		return (NULL);
	while (b < (c1 - c2 - 1) && b < (c1 - len(*p)))
		d[b++] = 32;
	d[b++] = '-';
	while (b < (a - len(*p) + 1) && (!(d[a] = '\0')))
		d[b++] = 48;
	while (p[0][i] != '\0')
		d[b++] = p[0][i++];
	if (j == 1)
		d = rev(d);
	ft_free(p);
	return (d);
}
