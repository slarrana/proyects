/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:13:31 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/27 12:13:26 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*string;
	size_t					a;

	string = s;
	a = 0;
	while (n > a)
	{
		if (string[a] == (unsigned char)c && n > a)
			return ((void *)(s + a));
		a++;
	}
	return (0);
}
