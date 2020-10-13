/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:53:03 by slarrana          #+#    #+#             */
/*   Updated: 2020/07/26 17:53:06 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H

# define LIBPRINTF_H

# include <stdarg.h>

typedef	struct	s_flag
{
	int			minum;
	int			zero;
	int			point;
	int			p;
	int			number;
	int			i;
	va_list		ap;
}				t_flag;

int				ft_printf(const char *format, ...);
char			*ft_uitoa(unsigned int d);
char			*ft_itoa_hexmin(int value);
char			*ft_itoa_hexmayus(int value);
char			*ft_adress(long int value);
void			ft_initialize_flags(t_flag *flags);
void			ft_value_flags(t_flag *flags, const char *format);
int				ft_check_flags_str(t_flag *flags, char *str);
int				ft_check_flags_n(t_flag *flags, int c, int d, int len);
int				ft_check_flags_adress(t_flag *flags, long int p);
int				ft_print_without_flags(t_flag *flags, char *str);
int				ft_print_minum(t_flag *flags, char *str, int len);
int				ft_print_p_n_z_n(t_flag *flags, char *num, int len, int sign);
int				ft_print_m_p_n(t_flag *flags, char *num, int len, int sign);
int				ft_print_p_zero_n(t_flag *flags, char *num, int len, int sign);
int				ft_print_number_n(t_flag *flags, char *num, int len);
int				ft_check_flags_char(t_flag *flags, int c);
int				asterisk(t_flag *flags);
int				ft_print_m_ad(t_flag *flags, char *adress, int len);
int				ft_print_without_flags_ad(t_flag *flags, char *adress);

#endif
