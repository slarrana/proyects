/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:43:43 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/29 17:16:29 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	size_t		a;

	if (dst == src)
		return (0);
	dest = dst;
	source = src;
	a = 0;
	if (dest > source)
	{
		while (len-- > a)
		{
			dest[len] = source[len];
		}
	}
	else
	{
		while (len > a)
		{
			dest[a] = source[a];
			a++;
		}
	}
	return (dst);
}
