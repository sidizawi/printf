/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:12:39 by szawi             #+#    #+#             */
/*   Updated: 2021/06/02 13:23:44 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(long k)
{
	int		i;

	i = 0;
	while (k)
	{
		k /= 10;
		i++;
	}
	i++;
	return (i);
}

static void	ft_rev_dest(char *dest)
{
	int		i;
	int		size;
	char	temp;

	size = ft_strlen(dest);
	i = 0;
	if (!size)
	{
		dest[0] = '0';
		dest[1] = 0;
	}
	while (i < (size / 2))
	{
		temp = dest[i];
		dest[i] = dest[size - i - 1];
		dest[size - i - 1] = temp;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	long	k;
	int		len;

	k = n;
	len = ft_nbr_len(k);
	if (n < 0)
		k *= -1;
	if (n <= 0)
		len += 1;
	dest = malloc(sizeof(char) * len);
	if (!dest)
		return (NULL);
	i = 0;
	while (k)
	{
		dest[i++] = (k % 10) + '0';
		k /= 10;
	}
	if (n < 0)
		dest[i++] = '-';
	dest[i] = '\0';
	ft_rev_dest(dest);
	return (dest);
}
