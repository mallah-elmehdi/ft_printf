/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:30:39 by emallah           #+#    #+#             */
/*   Updated: 2019/12/11 10:55:50 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(char const *s, ...)
{
	int		i;
	int		a;
	va_list	go;

	i = 0;
	if (s == NULL)
		return (-1);
	va_start(go, s);
	while (*s)
	{
		if (*s != '%' && ++i)
			write(1, s, 1);
		a = i;
		if (*s == '%' && ++s)
			i = i + ft_putstr(go, &s, *s);
		if (a > i || i < 0)
		{
			va_end(go);
			return (-1);
		}
		s++;
	}
	va_end(go);
	return (i);
}
