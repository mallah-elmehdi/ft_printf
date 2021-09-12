/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_and_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:16:05 by emallah           #+#    #+#             */
/*   Updated: 2019/12/09 20:34:55 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*s_and_flags(va_list go, const char **s, int j)
{
	int		a;
	int		c1;
	int		c2;
	char	*p;

	a = 0;
	while (**s == '-' && (*s = *s + 1))
		j = 1;
	if ((!(c1 = 0)) && **s == '*' && ++a)
		c1 = va_arg(go, int);
	while (s[0][a] >= '0' && s[0][a] <= '9')
		c1 = (c1 * 10) + (s[0][a++] - 48);
	if (c1 < 0 && (j = 1))
		c1 = -c1;
	if ((c2 = -1) && s[0][a++] == '.')
		c2 = 0;
	if (s[0][a] == '*' && ++a)
		c2 = va_arg(go, int);
	while (s[0][a] >= '0' && s[0][a] <= '9')
		c2 = (c2 * 10) + (s[0][a++] - 48);
	while (is_flag(**s))
		*s = *s + 1;
	p = ft_convertion(go, **s);
	return (s_output(&p, j, c1, c2));
}

char	*s_output(char **p, int j, int c1, int c2)
{
	char	*d;
	int		i;
	int		a;

	if ((!(i = 0)) && c2 < 0)
		c2 = len(*p);
	if ((!(a = 0)) && c2 < len(*p))
		p[0][c2] = '\0';
	if (c1 <= len(*p))
		return (*p);
	if (!(d = (char*)malloc(sizeof(char) * (c1 + 1))))
		return (NULL);
	while (i < (c1 - len(*p)))
		d[i++] = 32;
	while (p[0][a] != '\0')
		d[i++] = p[0][a++];
	d[i] = '\0';
	if (j == 1)
		d = rev(d);
	return (d);
}
