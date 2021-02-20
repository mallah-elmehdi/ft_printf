/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:27:22 by emallah           #+#    #+#             */
/*   Updated: 2019/12/09 21:24:47 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

char	*rest_output_1(va_list go, const char **s, int j);
char	*rest_output_2(va_list go, const char **s, int j);
char	*s_and_flags(va_list go, const char **s, int j);
char	*rest_and_flags(va_list go, const char **s);
char	*neg_case1(char **p, int c1, int c2, int j);
char	*s_output(char **p, int j, int c1, int c2);
char	*case1(char **p, int c1, int c2, int j);
char	*ft_flags(va_list go, const char **s);
char	*neg_case2(char **p, long c1, int j);
char	*ft_convertion(va_list go, char c);
char	*ft_itoh(unsigned long s, char c);
char	*case2(char **p, long c1, int j);
char	*ft_str(char *s);
char	*ft_itoa(long a);
char	*ft_char(int a);
char	*rev(char *d);

int		ft_putstr(va_list go, const char **s, char c);
int		ft_printf(char const *s, ...);
int		is_point(const char **s);
int		len_us(unsigned long n);
int		ft_free(char *s);
int		is_flag(char c);
int		is_conv(char c);
int		len_s(long n);

long	len(char *s);

#endif
