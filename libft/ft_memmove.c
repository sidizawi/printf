/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:47:14 by szawi             #+#    #+#             */
/*   Updated: 2021/02/03 20:28:09 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;

	if (!len)
		return (dst);
	else if (!src || !dst)
		return (NULL);
	else if (dst < src)
	{
		s = src;
		d = dst;
		while (len--)
			*d++ = *s++;
	}
	else
	{
		s = src + (len - 1);
		d = dst + (len - 1);
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
