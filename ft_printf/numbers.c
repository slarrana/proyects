/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:53:22 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/27 14:27:55 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libprintf.h"

int	ft_print_p_n_z_n(t_flag *flags, char *n, int len, int sign)
{
	if (n[0] == '0' && flags->p == 1 && flags->point == 0)
	{
		free(n);
		n = ft_strdup("");
	}
	sign = (n[0] == '-') ? -1 : 0;
	while (((len + (int)ft_strlen(n)) < flags->number && (len + flags->point)
	< (flags->number + sign)) || ((len + (int)ft_strlen(n)) < flags->zero
	&& (len + flags->point) < flags->zero + sign))
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	if (n[0] == '-')
		ft_putchar_fd('-', 1);
	while (len + (int)ft_strlen(n) < flags->number || len + (int)ft_strlen(n)
	< flags->zero || len + sign + (int)ft_strlen(n) < flags->point)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	ft_putstr_fd(((n[0] == '-') ? &n[1] : n), 1);
	flags->i++;
	return (len + ft_strlen(n));
}

int	ft_print_m_p_n(t_flag *flags, char *num, int len, int sign)
{
	if (num[0] == '0' && flags->point == 0 && flags->p == 1)
	{
		free(num);
		num = ft_strdup("");
	}
	if (num[0] == '-')
	{
		ft_putchar_fd('-', 1);
		sign = -1;
	}
	while (len + sign + (int)ft_strlen(num) < flags->point)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	ft_putstr_fd(((num[0] == '-') ? &num[1] : num), 1);
	while ((len + (int)ft_strlen(num)) < flags->minum)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	flags->i++;
	len += (int)ft_strlen(num);
	return (len);
}

int	ft_print_p_z_n(t_flag *flags, char *num, int len, int sign)
{
	if (num[0] == '0' && flags->point == 0 && flags->p == 1)
	{
		free(num);
		num = ft_strdup("");
	}
	if (num[0] == '-')
	{
		ft_putchar_fd('-', 1);
		sign = -1;
		if (flags->zero != 0)
			sign = 0;
	}
	while (len + sign + (int)ft_strlen(num) < flags->point ||
			len + sign + (int)ft_strlen(num) < flags->zero)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	if (num[0] == '-')
		ft_putstr_fd(&num[1], 1);
	else
		ft_putstr_fd(num, 1);
	len += ft_strlen(num);
	flags->i++;
	return (len);
}

int	ft_print_number_n(t_flag *flags, char *num, int len)
{
	while (len + (int)ft_strlen(num) < flags->number)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	ft_putstr_fd(num, 1);
	flags->i++;
	len += (int)ft_strlen(num);
	return (len);
}

int	ft_check_flags_n(t_flag *flags, int c, int d, int len)
{
	char	*num;

	if (c == 'u')
		num = ft_uitoa((unsigned int)d);
	else if (c == 'd' || c == 'i')
		num = ft_itoa(d);
	else if (c == 'x')
		num = ft_itoa_hexmin(d);
	else
		num = ft_itoa_hexmayus(d);
	if (flags->p == 0 && flags->number == 0
			&& flags->zero == 0 && flags->minum == 0)
		len = ft_print_without_flags(flags, num);
	else if (flags->p == 1 && (flags->number != 0 || flags->zero != 0))
		len = ft_print_p_n_z_n(flags, num, 0, 0);
	else if (flags->minum != 0 && flags->p == 1)
		len = ft_print_m_p_n(flags, num, 0, 0);
	else if (flags->p == 1 || flags->zero != 0)
		len = ft_print_p_z_n(flags, num, 0, 0);
	else if (flags->minum != 0)
		len = ft_print_minum(flags, num, 0);
	else if (flags->number != 0)
		len = ft_print_number_n(flags, num, 0);
	free(num);
	return (len);
}
