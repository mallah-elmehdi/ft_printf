/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_what.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:01:51 by emallah           #+#    #+#             */
/*   Updated: 2019/12/09 20:37:04 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		is_flag(char c)
{
	if (c == '.' || c == '*' || c == '-')
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		is_conv(char c)
{
	if (c == 'd' || c == 'i' || c == 'c')
		return (1);
	else if (c == 'X' || c == 'p' || c == 'x')
		return (1);
	else if (c == 's' || c == 'u' || c == '%')
		return (1);
	return (0);
}

int		is_point(const char **s)
{
	int i;

	i = 0;
	while (is_flag(s[0][i]))
		i++;
	if (s[0][i] == '%')
		return (0);
	i = 0;
	while (!(is_conv(s[0][i])))
	{
		if (s[0][i] == '.')
			return (1);
		i++;
	}
	return (0);
}
