/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:15:06 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/27 12:11:09 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	a;

	if (!s)
		return (0);
	a = ft_strlen(s);
	if (!(ret = ft_calloc((len + 1), sizeof(char))))
		return (0);
	if ((size_t)start > a)
		return (ret);
	a = 0;
	while (a < len)
	{
		ret[a] = s[start + a];
		a++;
	}
	return (ret);
}
