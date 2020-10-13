/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:52:17 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/26 17:52:21 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libprintf.h"

static void	negative(unsigned int n, int fd)
{
	char	c;
	long	a;

	a = n;
	if (a > 9)
		negative(a / 10, fd);
	c = (a % 10) + '0';
	ft_putchar_fd(c, fd);
}

void		ft_putunbr_fd(int n, int fd)
{
	if (n >= 0)
		ft_putnbr_fd(n, fd);
	if (n < 0)
		negative((unsigned int)n, fd);
}
