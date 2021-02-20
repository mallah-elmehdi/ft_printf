/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:29:39 by emallah           #+#    #+#             */
/*   Updated: 2019/11/25 21:01:01 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_here.h"

int		ft_printf(const char *s, ...)
{
	int i;
	int a;
	va_list	here;

	i = 0;
	a = 0;
	va_start(here, s);
	while (s[i] != '\0')
	{
		if (s[i] != '%' && ++a)
			write (1, &s[i], 1);
		else
		{
			i++;
			if (s[i] == '0' || s[i] == '.' || s[i] == '*' || s[i] == '-')
				i = flags(&s, &i);
			else
				a = a + specifier(&s, &i);
			i++;
		}
	}
	return (a);
}

int		specifier(const char **s, int *i)
{
	int a;
	va_list here;

	a = 0;
	if (s[0][*i] == 'i' || s[0][*i] == 'd' || s[0][*i] == 'c')
		a = ft_putunc(va_arg(here, int), s[0][*i]);
	else if (s[0][*i] == 'x' || s[0][*i] == 'X' || s[0][*i] == 'p')
		a = dtoxp(va_arg(here, unsigned long), s[0][*i]);
	else if (s[0][*i] == 's')
		a = ft_putstr(va_arg(here, char*));
	else if (s[0][*i] == 'u')
		a = ft_putunc(va_arg(here, unsigned int), s[0][*i]);
	else if (s[0][*i] == '%' && ++a)
		a = write(1, &s[0][*i], 1);
	return (a);
}

int		flags(const char **s, int *i)
{
	int a;
	int b;
	int c;
	va_list here;

	a = 0;
	b = 0;
	while (s[0][*i] == '0' || s[0][*i] == '.' || s[0][*i] == '*' || s[0][*i] == '-')
	{
		if (s[0][*i] == '-')
			a = 1;
		if (s[0][*i] == '0')
			b = 1;
		if (s[0][*i] =='*')
		{
			c = va_arg(here, int);
			*i = *i + 1;
			if (a && (a = specifier(s, i)))
			{
				if (c - a >= 0)
					w_0_s(a - b , b);
				return (c - a);
			}
			return (a);
		}
		*i = *i + 1;
	}
	return (*i);
}

void	w_0_s(int a, int b)
{
	if (b == 1)
	{
		while (a)
		{
			write(1, "0", 1);
			a--;
		}
	}
	else
	{
		while (a)
		{
			write(1, " ", 1);
			a--;
		}
	}
}
