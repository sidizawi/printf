/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:46:56 by szawi             #+#    #+#             */
/*   Updated: 2021/06/09 15:21:40 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// other[width, precision]

int	ft_put_str(char start, char *s, int *other)
{
	int	len;
	int	diff;
	int	i;

	len = 0;
	if (start != '0' || other[0] < 0)
		start = ' ';
	if (!s)
		s = "(null)";
	i = (int)ft_strlen(s);
	if (other[1] >= 0 && other[1] < i)
		i = other[1];
	diff = ft_abs(other[0]) - i;
	if (other[0] >= 0 && diff > 0)
		len += ft_put_n_char(diff, start);
	len += i;
	while (s && *s && i--)
		write(1, s++, 1);
	if (other[0] < 0 && diff > 0)
		len += ft_put_n_char(diff, start);
	return (len);
}
