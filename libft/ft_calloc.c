/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 01:10:21 by szawi             #+#    #+#             */
/*   Updated: 2021/03/25 12:59:03 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	size_t	i;
	size_t	len;

	if (count == 0 || size == 0)
		len = 1;
	else
		len = size * count;
	tab = malloc(len);
	if (!tab)
		return (NULL);
	i = 0;
	while (len--)
		tab[i++] = 0;
	return (tab);
}
