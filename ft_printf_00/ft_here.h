/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:33:10 by emallah           #+#    #+#             */
/*   Updated: 2019/11/25 20:41:39 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HERE_H
# define FT_HERE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		dtoxp(unsigned long s, char c);
int		ft_strrev(char *s, char c);
int		ft_strlen(const char *s);
int		ft_putstr(const char *s);
int		ft_putunc(long s, char c);
void	ft_free(char *s);
int		ft_printf(const char *s, ...);
int     specifier(const char **s, int *i);
int     flags(const char **s, int *i);
void    w_0_s(int a, int b);

#endif
