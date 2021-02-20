/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 20:29:39 by emallah           #+#    #+#             */
/*   Updated: 2019/11/29 21:36:51 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_here.h"

int		ft_printf(const char *s, ...)
{
	va_list go;
	int i;

	va_start(go, s);
	if (s == NULL)
		return (-1);
	i = 0;
	while (*s)
	{
		if (*s != '%' && ++i)
			write(1, &s[0], 1);
		else
		{
			s++;			
			if (checkp((char *)s))
				i = i + p_flag(&s, go);
			else if (*s == '*' || *s == '-' || (*s >= '0' && *s <= '9'))
				i = i + out_flag(*s, &s, go);
			else
				i = i + specifier(*s, go);
		}
		s++;
	}
	return (i);
}

int		p_flag(const char **s, va_list here)
{
	int i;
	int a;
	char *d1;
	char *d2;

	i = 0;
	if (**s == '-')
		i = 1;
	a = zs_flag(s);
	d1 = fill(a, '.');
	*s = *s + 1; 
	a = zs_flag(s);
	d2 = fill(a, '0');
	if (ft_strlen(d1) <= ft_strlen(d2))
		return (p_out(d1, i, here, (char **)s));
	else if (ft_strlen(d1) > ft_strlen(d2))
		re_order(&d1, i, ft_strlen(d1));
	return (p_out(d1, i, here, (char **)s));
}

int p_out(char *d, int i, va_list ok, char **s)
{	
	if (**s == 'i' || **s == 'd' || **s == 'c')
		return (p_int(va_arg(ok, int), **s, i, &d));
	/*else if (c == 'x' || c == 'X' || c == 'p')
		return ();
	else if ()
		return ();*/
	else if (**s == 'u')
		return (p_int(va_arg(ok, unsigned int), **s, i, &d));
	return (0);
}

int	p_int(long n, char c, int a, char **s)
{
	char	*d;
	int		i;

	i = 0;
	if (c == 'c')
	{
		c = n;
		return (write (1, &c, 1));
	}
	else
	{
		d = (char *)malloc(sizeof(char) * 21);
		if (n < 0 && ((n = -n) > 0))
			d[i++] = '-';
		while (n)
		{
			d[i] = (n % 10) + 48;
			n = n / 10;
			i++;
		}
		d[i] = '\0';
	}
	return (p_rev(d, a, s, c));
}

int		p_rev(char *s, int a, char **d, char c)
{
	char	*hold;
	int		j;
	int		i;

	hold = (char*)malloc(sizeof(char) * ft_strlen(s) + 3);
	j = 0;
	i = ft_strlen(s) - 1;
	if (c == 'p')
	{
		hold[j++] = '0';
		hold[j++] = 'x';
	}
	while (i >= 0)
		hold[j++] = s[i--];
	hold[j] = '\0';
	return (output_p(hold, a, d));
}

int output_p(char *s, int a, char **d)
{
	int i;

	i = 0;
	while (d[0][i] != '\0')
	{
		if (d[0][i] == '0')
		{
			while (d[0][i] == '0')
				i++;
			a = ft_strlen(s) - 1;
			i--;
			while (a >= 0)
			{
				d[0][i] = s[a];
				i--;
				a--;
			}
			i = ft_strlen(*d) - 1;
		}
		i++;
	}
	write (1, *d, i);
	return (i);
}

void	re_order(char **d1, int i, int a)
{
	int j;

	j = 0;
	if (i == 1)
	{
		while (j < a)
		{
			d1[0][j] = '0';
			j++;
		}
	}
	j = ft_strlen(*d1);
	if (i == 0)
	{
		while (j > (ft_strlen(*d1) - a))
		{
			d1[0][j] = '0';
			j--;
		}
	}
}

int checkp(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int		specifier(char c, va_list here)
{
	if (c == 'i' || c == 'd' || c == 'c')
		return (ft_putunc(va_arg(here, int), c));
	else if (c == 'x' || c == 'X' || c == 'p')
		return (dtoxp(va_arg(here, unsigned long), c));
	else if (c == 's')
		return (ft_putstr(va_arg(here, char*)));
	else if (c == 'u')
		return (ft_putunc(va_arg(here, unsigned int), c));
	else if (c == '%')
		return (write(1, &c, 1));
	return (0);
}

int	out_flag(char c, const char **s, va_list ok)
{
	int i;
	int a;
	char *d;

	a = 0;
	i = 0;
	if (c == '-')
	{
		a = 1;
		*s = *s + 1;
		while (**s == '-')
			*s = *s + 1;
	}
	if (c == '.')
		*s = *s + 1;
	if ((c >= '0' && c <= '9') || (**s >= '0' && **s <= '9'))
		i = zs_flag(s);
	if (c == '*' || **s == '*')
	{
		i = va_arg(ok, int);
		*s = *s + 1;
	}
	d = fill(i, c);
	return (the_out(ok, **s, &d, a));
}

int the_out(va_list ok, char c, char **d, int i)
{
	if (c == 'i' || c == 'd' || c == 'c')
		return (out_int(va_arg(ok, int), c, d, i));
	else if (c == 'x' || c == 'X' || c == 'p')
		return (out_uint(va_arg(ok, unsigned long), c, d, i));
	else if(c == 's')
		return (strout(va_arg(ok, char *), c, d, i));
	else if (c == 'u')
		return (out_int(va_arg(ok, unsigned int), c, d, i));
	return (0);

}

char *fill(int i, char c)
{
	char *s;
	int j;
	int o;

	j = 0;
	o = 0;
	if (c == '0')
		o = 16;
	s = (char *)malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		s[j] = 32 + o;
		j++;
	}
	s[j] = '\0';
	return (s);
}
