/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:51:17 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/26 17:51:24 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libprintf.h"

static int	ndigit(long long int value)
{
	int					i;
	unsigned long int	num;

	num = (unsigned long int)value;
	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i);
}

char		*ft_adress(long int value)
{
	char				*op;
	char				*str;
	unsigned long int	num;
	long long int		i;

	if (!(value))
		return (strdup("0"));
	op = ft_strdup("0123456789abcdef");
	str = (char *)ft_calloc(ndigit(value) + 1, sizeof(char));
	num = (unsigned long int)value;
	i = ndigit(value);
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		i--;
		str[i] = op[num % 16];
		num = num / 16;
	}
	free(op);
	return (str);
}
