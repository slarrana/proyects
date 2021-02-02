/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:28:00 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 18:09:13 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_perimet(t_pars *pars)
{
	int	i;
	int	f;

	f = 0;
	i = 0;
	if (pars->height < 3 || pars->width < 3)
		map_error(pars, "Error\nMapa Invalido\n");
	while (i < pars->width)
	{
		f = check_first_line(pars, i, f);
		f = check_last_line(pars, i, f);
		i++;
	}
	i = 0;
	while (i < pars->height)
	{
		f = check_first_column(pars, i, f);
		f = check_last_column(pars, i, f);
		i++;
	}
	if (f == 1)
		map_error(pars, "Error\nMapa Invalido\n");
}
