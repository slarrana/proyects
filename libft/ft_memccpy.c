/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:50:08 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/27 14:04:24 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	const char		*source;
	size_t			a;

	a = 0;
	dest = dst;
	source = src;
	while (n > a)
	{
		dest[a] = source[a];
		if (dest[a] == (unsigned char)c)
			return (dst + a + 1);
		a++;
	}
	return (0);
}
