/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:22:06 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/29 17:15:18 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *a;
	char *b;

	if (dst == src)
		return (0);
	a = dst;
	b = (char *)src;
	while (n > 0)
	{
		*a = *b;
		a++;
		b++;
		n--;
	}
	return (dst);
}
