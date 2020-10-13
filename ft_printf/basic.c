/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:47:54 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/26 17:48:00 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libprintf.h"

int			ft_print_without_flags(t_flag *flags, char *str)
{
	ft_putstr_fd(str, 1);
	flags->i++;
	return (ft_strlen(str));
}

int			ft_print_minum(t_flag *flags, char *str, int len)
{
	ft_putstr_fd(str, 1);
	while ((len + (int)ft_strlen(str)) < flags->minum)
	{
		ft_putchar_fd(' ', 1);
		len++;
	}
	flags->i++;
	len += (int)ft_strlen(str);
	return (len);
}

void		ft_initialize_flags(t_flag *flags)
{
	flags->minum = 0;
	flags->zero = 0;
	flags->point = 0;
	flags->p = 0;
	flags->number = 0;
	flags->i++;
}

int			asterisk(t_flag *flags)
{
	int flag;

	flag = va_arg(flags->ap, int);
	flags->i++;
	return (flag);
}
