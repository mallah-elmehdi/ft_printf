/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftpintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 18:43:15 by emallah           #+#    #+#             */
/*   Updated: 2019/12/04 18:59:43 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

char	*ft_itoh(unsigned long s, char c);
int		len_s(long n);
int		len_us(unsigned long n);
char	*ft_itoa(long a);
char	*ft_convertion(va_list go, char c);
int		ft_strlen(char *s);
char	*flag_p(long c, long c2, int j);
long	counter(const char *s, va_list go);
char	*ft_output(char c, char **d, int j, va_list go);
int		is_flag(char c);
int		is_conv(char c);
char	*ft_flags(va_list go, const char **s, char c);
int		ft_printf(char const *s, ...);
int		ft_putstr(va_list go, const char **s, char c);
char	*ft_flag_w(const char **s, int i, int j, va_list go);
int     last_0(char **s, int j);
int		is_point(const char **s);
char	*change(char **d);
char	*change1(char **d);
char	*s_conv(char **d, char *s);

#endif
