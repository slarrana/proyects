/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:23:40 by slarrana          #+#    #+#             */
/*   Updated: 2021/02/01 17:24:19 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_hex(const char *str)
{
	int				a;
	unsigned int	num;

	a = 0;
	num = 0;
	while (str[a] == ' ' || str[a] == '\t' || str[a] == '\n' ||
			str[a] == '\v' || str[a] == '\f' || str[a] == '\r')
		a++;
	while ((str[a] >= '0' && str[a] <= '9') || (str[a] >= 'A' && str[a] <= 'F'))
	{
		if (str[a] >= '0' && str[a] <= '9')
			num = num * 16 + (str[a] - '0');
		else
			num = num * 16 + (str[a] - 'A' + 10);
		a++;
	}
	return (num);
}
