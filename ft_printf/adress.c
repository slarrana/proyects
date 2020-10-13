/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:46:33 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/26 17:46:37 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libprintf.h"

static int	ft_print_point_number(t_flag *flags, char *ad, int len, int pt)
{
	if (flags->p == 1 && flags->point == 0)
		ad = ft_strdup("");
	while (((len + 2 + (int)ft_strlen(ad)) < flags->number
				&& (len + 2 + flags->point) < flags->number)
			|| ((len + 2 + (int)ft_strlen(ad)) < flags->zero
				&& (len + 2 + flags->point) < flags->zero))
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	ft_putstr_fd("0x", 1);
	pt = 2;
	while (len + pt + (int)ft_strlen(ad) < flags->number
			|| len + pt + (int)ft_strlen(ad) < flags->zero
			|| len + (int)ft_strlen(ad) < flags->point)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	ft_putstr_fd(ad, 1);
	len += ft_strlen(ad) + 2;
	flags->i++;
	return (len);
}

static int	ft_print_minum_point(t_flag *flags, char *ad, int len, int pt)
{
	if (flags->p == 1 && flags->point == 0)
		ad = ft_strdup("");
	ft_putstr_fd("0x", 1);
	pt = 2;
	while (len + (int)ft_strlen(ad) < flags->point)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	ft_putstr_fd(ad, 1);
	while ((len + pt + (int)ft_strlen(ad)) < flags->minum)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	flags->i++;
	len += (int)ft_strlen(ad) + 2;
	return (len);
}

static int	ft_print_point_or_zero(t_flag *flags, char *ad, int len, int pt)
{
	if (flags->p == 1 && flags->point == 0)
		ad = ft_strdup("");
	ft_putstr_fd("0x", 1);
	pt = 2;
	while (len + (int)ft_strlen(ad) < flags->point
			|| len + pt + (int)ft_strlen(ad) < flags->zero)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	ft_putstr_fd(ad, 1);
	len += ft_strlen(ad) + 2;
	flags->i++;
	return (len);
}

static int	ft_print_number(t_flag *flags, char *adress, int len)
{
	while (len + 2 + (int)ft_strlen(adress) < flags->number)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(adress, 1);
	flags->i++;
	len += (int)ft_strlen(adress) + 2;
	return (len);
}

int			ft_check_flags_adress(t_flag *flags, long int p)
{
	char	*adress;
	int		len;

	adress = ft_adress(p);
	len = 0;
	if (flags->number == 0 && flags->minum == 0
	&& flags->zero == 0 && flags->p == 0)
		len = ft_print_without_flags_ad(flags, adress);
	else if (flags->p == 1 && (flags->number != 0 || flags->zero != 0))
		len = ft_print_point_number(flags, adress, len, 0);
	else if (flags->minum != 0 && flags->p == 1)
		len = ft_print_minum_point(flags, adress, len, 0);
	else if (flags->p == 1 || flags->zero != 0)
		len = ft_print_point_or_zero(flags, adress, len, 0);
	else if (flags->number != 0)
		len = ft_print_number(flags, adress, len);
	else if (flags->minum != 0)
		len = ft_print_m_ad(flags, adress, len);
	free(adress);
	return (len);
}
