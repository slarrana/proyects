/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:59:06 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/29 16:19:36 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s, char c)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (s[a] == c)
		a++;
	while (s[a] != c && s[a++])
		b++;
	return (b);
}

int	ft_words(char const *s, char c)
{
	int a;
	int	b;

	a = 0;
	b = 0;
	while (s[a] != 0)
	{
		if (s[a] != c)
			b++;
		while (s[a] != c && s[a + 1])
			a++;
		a++;
	}
	return (b);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	int		a;
	int		b;
	int		d;

	if (!s || (!(str = ft_calloc(ft_words(s, c) + 1, sizeof(char*)))))
		return (0);
	a = 0;
	b = 0;
	while (a < ft_words(s, c))
	{
		if (!(str[a] = ft_calloc(ft_len(&s[b], c) + 1, (sizeof(char)))))
			return (0);
		d = 0;
		while (s[b] == c)
			b++;
		while ((s[b] != c) && s[b])
			str[a][d++] = s[b++];
		a++;
	}
	return (str);
}
