/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:37:07 by emallah           #+#    #+#             */
/*   Updated: 2019/12/11 22:34:28 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putstr(va_list go, const char **s, char c)
{
	char	*d;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (is_conv(c) && (!(d = ft_convertion(go, c))))
		return (-1);
	else if (is_flag(c) && (!(d = ft_flags(go, s))))
		return (-1);
	if (**s == 'c')
	{
		while (d[a] == 32 && d[a] != '\0')
			a++;
		if (len(d) == a)
			i++;
	}
	i = i + write(1, d, len(d));
	ft_free(&d);
	return (i);
}
