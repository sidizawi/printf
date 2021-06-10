/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:01:42 by szawi             #+#    #+#             */
/*   Updated: 2021/02/03 20:13:55 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (!n || dst == src || !dst)
		return (dst);
	else if (!src)
		return (NULL);
	s = src;
	d = dst;
	while (n--)
		d[n] = s[n];
	return (dst);
}
