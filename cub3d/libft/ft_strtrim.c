/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:49:23 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/29 19:24:25 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	a;
	size_t	b;

	a = 0;
	if (!s1 || !set)
		return (0);
	while (s1[a] != 0 && ft_strchr(set, s1[a]))
		a++;
	if (s1[a] == 0)
		return (ft_strdup(""));
	b = ft_strlen(s1);
	while (b && ft_strchr(set, s1[b]))
		b--;
	str = ft_substr(s1, a, (b - a) + 1);
	return (str);
}
