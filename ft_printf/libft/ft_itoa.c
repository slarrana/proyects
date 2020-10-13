/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:59:15 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/27 13:59:13 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nabs(int n)
{
	unsigned int d;

	if (n < 0)
		d = -n;
	else
		d = n;
	return (d);
}

static int			ft_cont(int a)
{
	int	c;

	c = 1;
	while (a > 9 || a < -9)
	{
		a = a / 10;
		c++;
	}
	return (c);
}

static int			ft_isnegative(int n)
{
	int b;

	b = 0;
	if (n < 0)
		b = 1;
	return (b);
}

char				*ft_itoa(int n)
{
	char			*str;
	int				b;
	int				c;
	unsigned int	d;

	b = ft_isnegative(n);
	c = ft_cont(n);
	if (!(str = (char *)ft_calloc(c + b + 1, sizeof(char))))
		return (0);
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	d = ft_nabs(n);
	while ((c + b) > b)
	{
		c--;
		str[c + b] = (d % 10) + '0';
		d = d / 10;
	}
	if (b == 1)
		str[c] = '-';
	return (str);
}
