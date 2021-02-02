/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 17:39:39 by slarrana          #+#    #+#             */
/*   Updated: 2020/02/01 20:56:23 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	if (needle[0] == 0 || haystack == needle)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	a = 0;
	while (haystack[a] != 0 && a < len)
	{
		if (haystack[a] == needle[0])
		{
			b = 1;
			while (needle[b] != 0 && haystack[a + b] == needle[b] &&
					(a + b) < len)
				b++;
			if (needle[b] == 0)
				return ((char *)&haystack[a]);
		}
		a++;
	}
	return (0);
}
