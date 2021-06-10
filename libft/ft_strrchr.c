/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:41:39 by szawi             #+#    #+#             */
/*   Updated: 2021/04/08 00:22:59 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		last;

	i = 0;
	last = -1;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			last = i;
		i++;
	}
	if (s && s[i] == (char)c)
		return ((char *)&s[i]);
	else if (!s || last < 0)
		return (NULL);
	else
		return ((char *)&s[last]);
}
