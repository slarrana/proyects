/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:45:30 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/24 18:51:31 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	a;
	unsigned int	b;

	if (!s)
		return (0);
	b = ft_strlen(s);
	if (!(str = (char *)malloc((b + 1) * sizeof(char))))
		return (0);
	a = 0;
	while (s[a] != 0)
	{
		str[a] = f(a, s[a]);
		a++;
	}
	str[a] = '\0';
	return (str);
}
