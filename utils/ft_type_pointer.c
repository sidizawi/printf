/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:49:16 by szawi             #+#    #+#             */
/*   Updated: 2021/06/09 16:18:51 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// other[width, precision]
static void	ft_put_hexadecimal(unsigned long val)
{
	char	temp;
	char	*hex;

	hex = "0123456789abcdef";
	if (val >= 16)
	{
		ft_put_hexadecimal(val / 16);
		temp = hex[val % 16];
		write(1, &temp, 1);
	}
	else
	{
		temp = hex[val % 16];
		write(1, &temp, 1);
	}
}

int	ft_put_pointer(char start, unsigned long val, int *other)
{
	int		len;
	int		diff;
	int		diff_prec;

	if (start != '0' || other[0] < 0)
		start = ' ';
	len = ft_hex_len(val);
	if (!val && !other[1])
		len = 0;
	diff_prec = other[1] - len;
	len += 2;
	diff = ft_abs(other[0]) - len - ft_positif(diff_prec);
	if (other[0] > 0 && diff > 0 && start == ' ')
		len += ft_put_n_char(diff, start);
	write(1, "0x", 2);
	if (other[0] > 0 && diff > 0 && start == '0')
		len += ft_put_n_char(diff, start);
	if (other[1] > 0 && diff_prec > 0)
		len += ft_put_n_char(diff_prec, '0');
	if (val || other[1])
		ft_put_hexadecimal(val);
	if (other[0] < 0 && diff > 0)
		len += ft_put_n_char(diff, start);
	return (len);
}
