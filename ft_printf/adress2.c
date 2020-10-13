/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:42:56 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/26 17:45:12 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libprintf.h"

int	ft_print_m_ad(t_flag *flags, char *adress, int len)
{
	ft_putstr_fd("0x", 1);
	len = 2;
	return (ft_print_minum(flags, adress, len));
}

int	ft_print_without_flags_ad(t_flag *flags, char *adress)
{
	ft_putstr_fd("0x", 1);
	return (ft_print_without_flags(flags, adress) + 2);
}
