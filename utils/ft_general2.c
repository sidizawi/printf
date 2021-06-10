/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:44:12 by szawi             #+#    #+#             */
/*   Updated: 2021/06/05 20:56:52 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_len(const char *s)
{
	int		i;
	char	*specif;

	specif = "cspdiuxX%";
	i = 1;
	while (s[i] == '-' || s[i] == '0' || s[i] == ' ')
		i++;
	if ((s[i] == '*' || ft_isdigit(s[i])) && i++)
	{
		while (ft_isdigit(s[i]))
			i++;
	}
	if (s[i] == '.' && i++)
	{
		while (ft_isdigit(s[i]) || s[i] == '*')
			i++;
	}
	while (*specif)
	{
		if (s[i] == *specif++)
			return (i);
	}
	return (0);
}

int	ft_put_n_char(int n, char c)
{
	int	len;

	len = n;
	while (n--)
		write(1, &c, 1);
	return (len);
}

int	ft_hex_len(unsigned long val)
{
	int	i;

	i = 0;
	if (val == 0)
		return (1);
	while (val > 0 && ++i)
		val /= 16;
	return (i);
}

int	ft_supp(int *width, int len)
{
	if (len > 1)
	{
		if (width[0] >= 0)
			width[0] -= 1;
		else
			width[0] += 1;
		return (1);
	}
	return (0);
}
