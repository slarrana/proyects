/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:51:51 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/26 17:51:54 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libprintf.h"

static int	ft_cond(t_flag *flags, const char *format)
{
	int len;

	len = 0;
	ft_initialize_flags(flags);
	ft_value_flags(flags, format);
	if (format[flags->i] == 'c')
		len += ft_check_flags_char(flags, va_arg(flags->ap, int));
	else if (format[flags->i] == 's')
		len += ft_check_flags_str(flags, va_arg(flags->ap, char *));
	else if (format[flags->i] == 'd'
		|| format[flags->i] == 'i' || format[flags->i] == 'u'
		|| format[flags->i] == 'x' || format[flags->i] == 'X')
		len +=
		ft_check_flags_n(flags, format[flags->i], va_arg(flags->ap, int), 0);
	else if (format[flags->i] == 'p')
		len += ft_check_flags_adress(flags, va_arg(flags->ap, long int));
	else if (format[flags->i] == '%')
		len += ft_check_flags_str(flags, "%");
	return (len);
}

static int	ft_print_char(t_flag *flags, const char *format)
{
	write(1, &format[flags->i], 1);
	flags->i++;
	return (1);
}

static int	ft_print_percent(t_flag *flags, const char *format)
{
	write(1, &format[flags->i], 1);
	flags->i += 2;
	return (1);
}

int			ft_printf(const char *format, ...)
{
	t_flag	*flags;
	int		len;

	len = 0;
	flags = (t_flag *)malloc(sizeof(t_flag));
	va_start(flags->ap, format);
	flags->i = 0;
	while (format[flags->i] != 0)
	{
		if (format[flags->i] != '%')
			len += ft_print_char(flags, format);
		else if (format[flags->i] == '%' && format[flags->i + 1] == '%')
			len += ft_print_percent(flags, format);
		else
			len += ft_cond(flags, format);
	}
	va_end(flags->ap);
	free(flags);
	return (len);
}
