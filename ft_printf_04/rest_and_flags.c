/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rest_and_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:36:13 by emallah           #+#    #+#             */
/*   Updated: 2019/12/10 10:45:27 by emallah          ###   ########.fr       */
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
