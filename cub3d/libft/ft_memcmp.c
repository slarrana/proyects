/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:35:35 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/27 14:06:56 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *c1;
	const unsigned char *c2;
	size_t				a;

	c1 = s1;
	c2 = s2;
	a = 0;
	while (n > a)
	{
		if (c1[a] != c2[a])
			return (c1[a] - c2[a]);
		a++;
	}
	return (0);
}
