/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:38:50 by szawi             #+#    #+#             */
/*   Updated: 2021/06/09 16:24:38 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
char	ft_get_type(const char *s);
int		ft_get_width(const char *form);
int		ft_get_precision(const char *form);
int		ft_abs(int num);
int		ft_get_len(const char *s);
int		ft_put_n_char(int n, char c);
int		ft_positif(int n);
int		ft_hex_len(unsigned long val);
int		ft_put_char(char start, int val, int width);
int		ft_put_int(char start, int val, int *other);
int		ft_put_unsigned(char start, unsigned int val, int *other);
int		ft_put_str(char start, char *s, int *other);
int		ft_put_pointer(char start, unsigned long val, int *other);
int		ft_put_hex(char start, char type, unsigned int val, int *other);
int		ft_put_percent(char start, int width);
int		ft_supp(int *width, int len);

#endif
