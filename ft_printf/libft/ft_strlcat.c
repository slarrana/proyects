/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:15:31 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/24 18:24:29 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t total;
	size_t dstsize;

	dstsize = size;
	total = ft_strlen(dst) + ft_strlen(src);
	while (*dst != 0 && size > 0)
	{
		dst++;
		size--;
	}
	if (size == 0)
		return (dstsize + ft_strlen(src));
	while (*src != 0 && size > 1)
	{
		*dst = *src;
		size--;
		dst++;
		src++;
	}
	*dst = 0;
	return (total);
}
