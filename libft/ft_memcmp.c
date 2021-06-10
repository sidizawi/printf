/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:46:28 by szawi             #+#    #+#             */
/*   Updated: 2021/03/25 13:15:09 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*d1;
	const char	*d2;

	i = 0;
	d1 = (const char *)s1;
	d2 = (const char *)s2;
	while (s1 && s2 && i < n)
	{
		if ((unsigned char)d1[i] != (unsigned char)d2[i])
			return ((unsigned char)d1[i] - (unsigned char)d2[i]);
		i++;
	}
	return (0);
}
