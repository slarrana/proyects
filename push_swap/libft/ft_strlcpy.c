/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 12:14:45 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/29 16:24:41 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t a;
	size_t b;

	if (!dst && !src)
		return (0);
	a = 0;
	while (src[a] != '\0')
		a++;
	if (dstsize == 0)
		return (a);
	b = 0;
	while (b < (dstsize - 1) && src[b] != '\0')
	{
		dst[b] = src[b];
		b++;
	}
	dst[b] = '\0';
	return (a);
}
