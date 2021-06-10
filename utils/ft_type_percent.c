/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:42:18 by szawi             #+#    #+#             */
/*   Updated: 2021/06/05 23:41:08 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_put_percent(char start, int width)
{
	int	len;
	int	diff;

	len = 1;
	if (start != '0' || width <= 0)
		start = ' ';
	diff = ft_abs(width) - len;
	if (width > 1)
		len += ft_put_n_char(diff, start);
	write(1, "%", 1);
	if (width < -1)
		len += ft_put_n_char(diff, start);
	return (len);
}
