/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:26:44 by szawi             #+#    #+#             */
/*   Updated: 2021/06/03 00:59:53 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if n < 0 => write(fd, "-", 1);
// but here because of printf

void	ft_putnbr_fd(int n, int fd)
{
	char			temp;
	unsigned int	nb;

	nb = n;
	if (fd >= 0)
	{
		if (n < 0)
			nb = -n;
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			temp = nb % 10 + 48;
			write(fd, &temp, 1);
		}
		else
		{
			temp = nb + 48;
			write(fd, &temp, 1);
		}
	}
}
