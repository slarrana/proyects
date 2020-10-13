/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:52:40 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/26 17:52:44 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libprintf.h"

static int	ft_count(unsigned int d)
{
	int c;

	c = 1;
	while (d > 9)
	{
		d = d / 10;
		c++;
	}
	return (c);
}

char		*ft_uitoa(unsigned int d)
{
	char	*str;
	int		i;

	i = ft_count(d);
	if (!(str = (char *)ft_calloc(i + 1, sizeof(char))))
		return (0);
	if (d == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (i > 0)
	{
		i--;
		str[i] = (d % 10) + '0';
		d = d / 10;
	}
	return (str);
}
