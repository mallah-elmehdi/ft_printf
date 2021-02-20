/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_output_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 10:43:51 by emallah           #+#    #+#             */
/*   Updated: 2019/12/11 16:34:00 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*rest_output_2(va_list go, const char **s, int j, long c1)
{
	int		i;
	char	*p;

	i = 0;
	while (**s == '-' && (*s = *s + 1))
		j = 1;
	while (**s == '0' && (*s = *s + 1))
		j = 16;
	if (**s == '*' && ++i)
		c1 = va_arg(go, int);
	while (s[0][i] >= '0' && s[0][i] <= '9')
		c1 = (c1 * 10) + (s[0][i++] - 48);
	if (c1 < 0 && (j = 1))
		c1 = -c1;
	while (is_flag(**s))
		*s = *s + 1;
	p = ft_convertion(go, **s);
	if (**s == 'c' && *p == '\0')
		c1--;
	return (case2(&p, c1, j));
}

char	*case2(char **p, int c1, int j)
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
	ft_free(p);
	return (d);
}

char	*neg_case2(char **p, int c1, int j)
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
	ft_free(p);
	return (d);
}
