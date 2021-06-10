/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:09:37 by szawi             #+#    #+#             */
/*   Updated: 2021/06/02 12:22:05 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_len(const char *s, char c)
{
	static int	len;

	if (len > 0)
		return (len);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
			s++;
		len++;
	}
	if (len > 0)
	{
		s--;
		if (*s == c)
			len--;
	}
	return (len);
}

static int	ft_sub_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static void	*ft_free_tab(char **tab)
{
	int	j;

	j = 0;
	while (tab[j])
		free(tab[j++]);
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_get_len(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ft_get_len(s, c))
	{
		while (*s && *s == c)
			s++;
		tab[i] = malloc(sizeof(char) * ft_sub_len(s, c) + 1);
		if (!tab[i])
			return (ft_free_tab(tab));
		j = 0;
		while (*s && *s != c)
			tab[i][j++] = *s++;
		tab[i][j] = 0;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
