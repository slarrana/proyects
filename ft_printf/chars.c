/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:48:39 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/26 17:48:43 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libprintf.h"

static int	ft_print_without_flags_char(t_flag *flags, int c)
{
	write(1, &c, 1);
	flags->i++;
	return (1);
}

static int	ft_print_minum_char(t_flag *flags, int c, int len)
{
	write(1, &c, 1);
	while ((len + 1) < flags->minum)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	flags->i++;
	return (len + 1);
}

static int	ft_print_number_or_zero_char(t_flag *flags, int c, int len)
{
	while ((len + 1) < flags->number)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	while ((len + 1) < flags->zero)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	write(1, &c, 1);
	flags->i++;
	return (len + 1);
}

int			ft_check_flags_char(t_flag *flags, int c)
{
	int len;

	len = 0;
	if (flags->number == 0 && flags->zero == 0 && flags->minum == 0)
		len = ft_print_without_flags_char(flags, c);
	else if (flags->minum != 0)
		len = ft_print_minum_char(flags, c, 0);
	else if (flags->number != 0 || flags->zero != 0)
		len = ft_print_number_or_zero_char(flags, c, 0);
	return (len);
}
