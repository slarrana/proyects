/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:49:46 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/27 13:41:10 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int a;
	int b;
	int num;

	a = 0;
	b = 1;
	num = 0;
	while (str[a] == ' ' || str[a] == '\t' || str[a] == '\n' ||
			str[a] == '\v' || str[a] == '\f' || str[a] == '\r')
		a++;
	if (str[a] == '-')
	{
		b = -1;
		a++;
	}
	else if (str[a] == '+')
		a++;
	while (str[a] >= '0' && str[a] <= '9')
	{
		num = num * 10 + (str[a] - '0');
		a++;
	}
	if (b == -1)
		num = -num;
	return (num);
}
