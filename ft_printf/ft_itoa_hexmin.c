/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexmin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:51:04 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/26 17:51:07 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libprintf.h"

static int	ndigit(int value)
{
	int				i;
	unsigned int	num;

	num = (unsigned int)value;
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

char		*ft_itoa_hexmin(int value)
{
	char			*op;
	char			*str;
	unsigned int	num;
	int				i;

	op = ft_strdup("0123456789abcdef");
	str = (char *)ft_calloc(ndigit(value) + 1, sizeof(char));
	num = (unsigned int)value;
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
