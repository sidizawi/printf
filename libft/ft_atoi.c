/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:03:13 by szawi             #+#    #+#             */
/*   Updated: 2021/06/02 12:26:17 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fill_nb(int nb, const char *str, int sign)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < 19)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (sign < 0 && i >= 19)
		nb = 0;
	else if (i >= 19)
		nb = -1;
	else if (i < 11 && sign < 0)
		nb *= sign;
	return (nb);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	nb = 0;
	if (str[i] >= '0' && str[i] <= '9')
		nb = ft_fill_nb(nb, &str[i], sign);
	return (nb);
}
