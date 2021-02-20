/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:33:10 by emallah           #+#    #+#             */
/*   Updated: 2019/11/29 21:27:37 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HERE_H
# define FT_HERE_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		specifier(char c, va_list here);
int		out_flag(char c, const char **s, va_list ok);
int		the_out(va_list ok, char c, char **d, int i);
char	*fill(int i, char c);
int		ft_putunc(long n, char c);
int		ft_putstr(char const *s);
int		dtoxp(unsigned long s, char c);
int		ft_strrev(char *s, char c);
int		ft_strlen(const char *s);
int		zs_flag(const char **d);
int		strout(char *s, char c, char **d, int i);
int		out_int(long n, char c, char **d, int i);
int		str_out_rev(char **d, char *s);
int		str_out(char **d, char **s, int max, int a);
char	*putd(long n, char c);
char	*str_rev(char **s);
int		out_uint(unsigned long s, char c, char **p, int m);
char	*ft_strrevx(char *s, char c);
void    ft_free(char *s);
int     p_flag(const char **s, va_list here);
int p_out(char *d, int i, va_list ok, char **s);
int p_int(long n, char c, int a, char **s);
int     p_rev(char *s, int a, char **d, char c);
int output_p(char *s, int a, char **d);
void    re_order(char **d1, int i, int a);
int checkp(char *s);

#endif
