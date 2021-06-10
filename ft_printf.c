/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:37:20 by szawi             #+#    #+#             */
/*   Updated: 2021/06/09 16:18:03 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_type(char type, char start, va_list *ag, int *other)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = ft_put_char(start, va_arg(*ag, int), other[0]);
	else if (type == 'd' || type == 'i')
		len = ft_put_int(start, va_arg(*ag, int), other);
	else if (type == 'u')
		len = ft_put_unsigned(start, va_arg(*ag, unsigned int), other);
	else if (type == 'p')
		len = ft_put_pointer(start, va_arg(*ag, unsigned long), other);
	else if (type == 'x' || type == 'X')
		len = ft_put_hex(start, type, va_arg(*ag, unsigned int), other);
	else if (type == 's')
		len = ft_put_str(start, va_arg(*ag, char *), other);
	else if (type == '%')
		len = ft_put_percent(start, other[0]);
	return (len);
}

static int	ft_put_elem(const char *s, va_list *ag)
{
	int		len;
	char	type;
	char	start;
	int		other[2];

	len = 1;
	while (s[len] == ' ')
		len++;
	if (len > 1)
		write(1, " ", 1);
	start = s[len];
	if (s[len] == '-' || s[len + 1] == '-')
		start = '-';
	other[0] = ft_get_width(s);
	other[1] = ft_get_precision(s);
	if (other[0] == -1)
		other[0] = va_arg(*ag, int);
	if (other[1] == -1)
		other[1] = va_arg(*ag, int);
	if (start == '-' && other[0] > 0)
		other[0] *= -1;
	len = ft_supp(&other[0], len);
	type = ft_get_type(s);
	len += ft_put_type(type, start, ag, other);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ag;
	int		len;
	int		i;

	if (!format)
		return (0);
	va_start(ag, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_get_type(&format[i]) != 'N')
			len += ft_put_elem(&format[i], &ag) - 1;
		if (format[i] == '%' && ft_get_type(&format[i]) != 'N')
			i += ft_get_len(&format[i]);
		else
			write(1, &format[i], 1);
		i += 1;
		len += 1;
	}
	va_end(ag);
	return (len);
}
