/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 20:43:57 by szawi             #+#    #+#             */
/*   Updated: 2021/06/05 21:09:38 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	ft_get_type(const char *s)
{
	int		i;
	char	*specif;

	i = 1;
	specif = "cspdiuxX%";
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
			return (s[i]);
	}
	return ('N');
}

int	ft_get_width(const char *form)
{
	int	i;
	int	res;

	i = 1;
	res = 0;
	while (form[i] == '-' || form[i] == '0' || form[i] == ' ')
		i++;
	if (form[i] == '*')
		return (-1);
	else
	{
		while (ft_isdigit(form[i]))
			res = res * 10 + form[i++] - '0';
	}
	return (res);
}

int	ft_get_precision(const char *form)
{
	int	i;
	int	res;

	i = 1;
	while (form[i] == '-' || form[i] == '0' || form[i] == ' ')
		i++;
	if (form[i] == '*')
		i++;
	else
	{
		while (ft_isdigit(form[i]))
			i++;
	}
	if (form[i] == '.' && form[i + 1] == '*')
		return (-1);
	res = 0;
	if (form[i] == '.' && ft_isdigit(form[i + 1]))
	{
		while (ft_isdigit(form[++i]))
			res = res * 10 + form[i] - '0';
	}
	else if (form[i] != '.')
		res = -2;
	return (res);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	ft_positif(int n)
{
	if (n <= 0)
		return (0);
	return (n);
}
