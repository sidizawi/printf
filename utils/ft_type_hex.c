/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:55:20 by szawi             #+#    #+#             */
/*   Updated: 2021/06/09 16:10:33 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// other[width, precision]

static void	ft_put_hexadecimal(unsigned int val, int maj)
{
	char	temp;
	char	*hex;

	hex = "0123456789abcdef";
	if (val >= 16)
	{
		ft_put_hexadecimal(val / 16, maj);
		if (maj)
			temp = ft_toupper(hex[val % 16]);
		else
			temp = hex[val % 16];
		write(1, &temp, 1);
	}
	else
	{
		if (maj)
			temp = ft_toupper(hex[val % 16]);
		else
			temp = hex[val % 16];
		write(1, &temp, 1);
	}
}

int	ft_put_hex(char start, char type, unsigned int val, int *other)
{
	int		len;
	int		diff;
	int		diff_prec;
	int		maj;

	maj = 0;
	if (type == 'X')
		maj = 1;
	len = ft_hex_len(val);
	if (start != '0' || (other[0] > 0 && other[1] >= 0) || other[0] < 0)
		start = ' ';
	if (!other[1] && !val)
		len = 0;
	diff_prec = other[1] - len;
	diff = ft_abs(other[0]) - len - ft_positif(diff_prec);
	if (other[0] > 0 && diff > 0)
		len += ft_put_n_char(diff, start);
	if (diff_prec > 0)
		len += ft_put_n_char(diff_prec, '0');
	if (other[1] || val)
		ft_put_hexadecimal(val, maj);
	if (other[0] < 0 && diff > 0)
		len += ft_put_n_char(diff, start);
	return (len);
}
