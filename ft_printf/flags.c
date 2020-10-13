/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:49:35 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/26 17:49:38 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"
#include "libft/libft.h"

static int	ft_value(t_flag *flags, const char *format)
{
	int n;

	flags->i++;
	if (format[flags->i] == '*')
		n = asterisk(flags);
	else
	{
		n = ft_atoi(&format[flags->i]);
		while (format[flags->i] >= '0' && format[flags->i] <= '9')
			flags->i++;
	}
	return (n);
}

static void	ifs_asterisc(t_flag *flags, const char *format)
{
	if (format[flags->i] == '*')
	{
		flags->number = asterisk(flags);
		if (flags->number < 0)
		{
			flags->minum = -flags->number;
			flags->number = 0;
		}
	}
}

static void	ifs_cond_flags(t_flag *flags, const char *format)
{
	ifs_asterisc(flags, format);
	if (format[flags->i] == '-')
	{
		flags->minum = ft_value(flags, format);
		if (flags->minum < 0)
			flags->minum = -flags->minum;
	}
	if (format[flags->i] == '0')
	{
		if (format[flags->i + 1] != '-')
		{
			flags->zero = ft_value(flags, format);
			if (flags->zero < 0)
			{
				flags->minum = -flags->zero;
				flags->zero = 0;
			}
		}
		else
			flags->i++;
	}
}

static void	cond_flags(t_flag *flags, const char *format)
{
	ifs_cond_flags(flags, format);
	if (format[flags->i] >= '1' && format[flags->i] <= '9')
	{
		flags->number = ft_atoi(&format[flags->i]);
		while (format[flags->i] >= '0' && format[flags->i] <= '9')
			flags->i++;
	}
	if (format[flags->i] == '.')
	{
		flags->point = ft_value(flags, format);
		flags->p++;
		if (flags->point < 0)
		{
			flags->point = 0;
			flags->p--;
		}
	}
}

void		ft_value_flags(t_flag *flags, const char *format)
{
	while (format[flags->i] != 's' && format[flags->i] != 'd'
			&& format[flags->i] != 'i' && format[flags->i] != 'u'
			&& format[flags->i] != 'x' && format[flags->i] != 'X'
			&& format[flags->i] != 'c' && format[flags->i] != 'p'
			&& format[flags->i] != '%')
	{
		cond_flags(flags, format);
		if (format[flags->i] == '\0' || (format[flags->i] != '*'
				&& format[flags->i] != '-' && format[flags->i] != '.'
				&& !(format[flags->i] >= '0' && format[flags->i] <= '9')))
			break ;
	}
}
