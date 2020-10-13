/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:20:48 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/24 18:10:33 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	a;

	a = n;
	if (a < 0)
	{
		ft_putchar_fd('-', fd);
		a = -a;
	}
	if (a > 9)
		ft_putnbr_fd(a / 10, fd);
	c = (a % 10) + '0';
	ft_putchar_fd(c, fd);
}
