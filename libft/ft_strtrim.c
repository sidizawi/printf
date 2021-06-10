/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:12:03 by szawi             #+#    #+#             */
/*   Updated: 2021/06/02 12:24:11 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_next_in_set(const char *s1, const char *set)
{
	while (*s1)
	{
		if (!ft_in_set(*s1, set))
			return (0);
		s1++;
	}
	return (1);
}

static int	ft_get_len(const char *s1, const char *set)
{
	int	len;

	while (ft_in_set(*s1, set))
		s1++;
	len = 0;
	while (!ft_next_in_set(s1++, set))
		len++;
	return (len);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	int		len;
	int		i;

	if (!s1 || !set)
		return (NULL);
	len = ft_get_len(s1, set) + 1;
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	while (ft_in_set(*s1, set))
		s1++;
	i = 0;
	while (!ft_next_in_set(s1, set))
		str[i++] = *s1++;
	str[i] = '\0';
	return (str);
}
