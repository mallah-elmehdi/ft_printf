/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:30:39 by emallah           #+#    #+#             */
/*   Updated: 2019/12/09 18:39:32 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(char const *s, ...)
{
	int		i;
	va_list	go;

	i = 0;
	if (s == NULL)
		return (-1);
	va_start(go, s);
	while (*s)
	{
		if (*s != '%' && ++i)
			write(1, s, 1);
		else
		{
			s++;
			if (is_conv(*s))
				i = i + ft_putstr(go, &s, *s);
			else if (is_flag(*s))
				i = i + ft_putstr(go, &s, *s);
		}
		s++;
	}
	return (i);
}
