/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:12:37 by emallah           #+#    #+#             */
/*   Updated: 2019/11/25 12:38:46 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_here.h"

void	ft_free(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
}