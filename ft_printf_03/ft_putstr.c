/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:37:07 by emallah           #+#    #+#             */
/*   Updated: 2019/12/08 16:20:14 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_putstr(va_list go, const char **s, char c)
{
	char	*d;
	int		i;

	if (is_conv(c))
	{
		d = ft_convertion(go, c);
		i = write(1, d, len(d));
		ft_free(d);
		return (i);
	}
	else if (is_flag(c))
	{
		d = ft_flags(go, s);
		i = write(1, d, len(d));
		ft_free(d);
		return (i);
	}
	return (0);
}
