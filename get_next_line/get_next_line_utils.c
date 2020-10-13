/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 04:13:04 by slarrana          #+#    #+#             */
/*   Updated: 2020/02/12 04:14:13 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;

	i = 0;
	if (s == NULL || ft_strlen(s) < start)
		return (ft_strdup(""));
	res = (char *)malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

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

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	a;
	size_t	b;

	a = 0;
	while (s1[a])
		a++;
	if (!(s = malloc((a + 1) * sizeof(char))))
		return (0);
	b = 0;
	while (s1[b])
	{
		s[b] = s1[b];
		b++;
	}
	s[b] = '\0';
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int a;

	a = 0;
	while (s[a] != c && s[a] != '\0')
		a++;
	if (s[a] == c)
		return ((char *)(s + a));
	return (0);
}
