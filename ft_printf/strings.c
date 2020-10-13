/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:53:40 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/27 13:59:33 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libprintf.h"

static int	ft_print_point_number_zero(t_flag *flags, char *str, int len)
{
	char	*substr;
	
	substr = ft_substr(str, 0, flags->point);
	while ((len + (int)ft_strlen(str)) < flags->number
	|| (len + flags->point < flags->number))
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	while ((len + (int)ft_strlen(str)) < flags->zero
	|| (len + flags->point < flags->zero))
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	ft_putstr_fd(substr, 1);
	flags->i++;
	len += ft_strlen(substr);
	free(substr);
	return (len);
}

static int	ft_print_point_minum(t_flag *flags, char *str, int len)
{
	char *substr;

	substr = ft_substr(str, 0, flags->point);
	ft_putstr_fd(substr, 1);
	while ((len + (int)ft_strlen(substr))
	< flags->minum)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	flags->i++;
	len += ft_strlen(substr);
	free(substr);
	return (len);
}

static int	ft_print_point(t_flag *flags, char *str)
{
	char *substr;
	int len;

	substr = ft_substr(str, 0, flags->point);
	ft_putstr_fd(substr,  1);
	flags->i++;
	len = ft_strlen(substr);
	free(substr);
	return (len);
}

static int	ft_print_number_or_zero(t_flag *flags, char *str, int len)
{
	while ((len + (int)ft_strlen(str)) < flags->number)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	while ((len + (int)ft_strlen(str)) < flags->zero)
	{
		ft_putchar_fd('0', 1);
		len++;
	}
	ft_putstr_fd(str, 1);
	flags->i++;
	len += ft_strlen(str);
	return (len);
}

int			ft_check_flags_str(t_flag *flags, char *str)
{
	int len;

	len = 0;
	if (!str)
		str = ft_strdup("(null)");
	if (flags->p == 0 && flags->number == 0
	&& flags->zero == 0 && flags->minum == 0)
		len += ft_print_without_flags(flags, str);
	else if (flags->p == 1 && (flags->number != 0 || flags->zero != 0))
		len += ft_print_point_number_zero(flags, str, 0);
	else if (flags->p == 1 && flags->minum != 0)
		len += ft_print_point_minum(flags, str, 0);
	else if (flags->p == 1)
		len += ft_print_point(flags, str);
	else if (flags->minum != 0)
		len += ft_print_minum(flags, str, 0);
	else if (flags->number != 0 || flags->zero != 0)
		len += ft_print_number_or_zero(flags, str, 0);
	return (len);
}
