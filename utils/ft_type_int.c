/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:40:18 by szawi             #+#    #+#             */
/*   Updated: 2021/06/05 22:39:06 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// other[width, precision]

static int	ft_nbr_len(long k)
{
	int		i;

	i = 0;
	if (!k)
		return (1);
	if (k < 0)
		k *= -1;
	while (k)
	{
		k /= 10;
		i++;
	}
	return (i);
}

static int	ft_diff(int diff, int val)
{
	if (val < 0)
		return (diff - 1);
	return (diff);
}

int	ft_put_int(char start, int val, int *other)
{
	int		diff;
	int		diff_prec;
	int		len;

	len = ft_nbr_len(val);
	if (start != '0' || other[0] < 0 || other[1] >= 0)
		start = ' ';
	if (!other[1] && !val)
		len = 0;
	diff_prec = other[1] - len;
	diff = ft_abs(other[0]) - len - ft_positif(diff_prec);
	diff = ft_diff(diff, val);
	if (val < 0 && start == '0')
		len += ft_put_n_char(1, '-');
	if (other[0] > 0 && diff > 0)
		len += ft_put_n_char(diff, start);
	if (val < 0 && start != '0')
		len += ft_put_n_char(1, '-');
	if (other[1] > 0 && diff_prec > 0)
		len += ft_put_n_char(diff_prec, '0');
	if (other[1] || val)
		ft_putnbr_fd(val, 1);
	if (other[0] < 0 && diff > 0)
		len += ft_put_n_char(diff, start);
	return (len);
}

static void	ft_putnbr_unsigned(unsigned int nb)
{
	char			temp;

	if (nb > 9)
	{
		ft_putnbr_unsigned(nb / 10);
		temp = nb % 10 + 48;
		write(1, &temp, 1);
	}
	else
	{
		temp = nb + 48;
		write(1, &temp, 1);
	}
}

int	ft_put_unsigned(char start, unsigned int val, int *other)
{
	int	diff;
	int	diff_prec;
	int	len;

	len = ft_nbr_len(val);
	if (start != '0' || other[0] < 0 || other[1] >= 0)
		start = ' ';
	if (!other[1] && !val)
		len = 0;
	diff_prec = other[1] - len;
	diff = ft_abs(other[0]) - len - ft_positif(diff_prec);
	if (other[0] > 0 && diff > 0)
		len += ft_put_n_char(diff, start);
	if (other[1] > 0 && diff_prec > 0)
		len += ft_put_n_char(diff_prec, '0');
	if (other[1] || val)
		ft_putnbr_unsigned(val);
	if (other[0] < 0 && diff > 0)
		len += ft_put_n_char(diff, start);
	return (len);
}
