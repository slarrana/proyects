/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:42:13 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/24 18:59:37 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	a;
	size_t	b;
	size_t	c;

	if (!s1 || !s2)
		return (0);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!(str = (char *)malloc((a + b + 1) * sizeof(char))))
		return (0);
	c = 0;
	while (c < a)
	{
		str[c] = s1[c];
		c++;
	}
	while ((c - a) < b)
	{
		str[c] = s2[c - a];
		c++;
	}
	str[c] = '\0';
	return (str);
}
