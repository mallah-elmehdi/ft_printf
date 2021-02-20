/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 17:13:55 by emallah           #+#    #+#             */
/*   Updated: 2019/12/09 20:36:25 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_flags(va_list go, const char **s)
{
	int		a;
	int		j;

	a = 0;
	j = 0;
	while (is_flag(s[0][a]))
		a++;
	if (s[0][a] == 's')
		return (s_and_flags(go, s, j));
	return (rest_and_flags(go, s));
}
