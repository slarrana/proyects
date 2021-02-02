/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:35:54 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/27 14:26:50 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
