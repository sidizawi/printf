/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:44:08 by szawi             #+#    #+#             */
/*   Updated: 2021/06/09 15:08:41 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_char(char start, int val, int width)
{
	int	len;
	int	diff;

	len = 1;
	if (start != '0' || width < 0)
		start = ' ';
	diff = ft_abs(width) - 1;
	if (width > 1)
		len += ft_put_n_char(diff, start);
	ft_putchar_fd(val, 1);
	if (width < -1)
		len += ft_put_n_char(diff, start);
	return (len);
}
