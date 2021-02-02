/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:06:34 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 18:06:50 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	first_column_arist(t_pars *pars, int i, int f)
{
	if (!((pars->map[i - 1][0] == ' ' || pars->map[i - 1][0] == '1') &&
	(pars->map[i + 1][0] == ' ' || pars->map[i + 1][0] == '1') &&
	(pars->map[i - 1][1] == ' ' || pars->map[i - 1][1] == '1') &&
	(pars->map[i + 1][1] == ' ' || pars->map[i + 1][1] == '1') &&
	(pars->map[i][1] == ' ' || pars->map[i][1] == '1')))
		f = 1;
	return (f);
}

int			check_first_column(t_pars *pars, int i, int f)
{
	if (pars->map[i][0] != ' ' && pars->map[i][0] != '1')
		f = 1;
	else if (pars->map[i][0] == ' ' && i > 0 && i < pars->height - 1)
		f = first_column_arist(pars, i, f);
	else if (pars->map[i][0] == ' ' && i == 0)
	{
		if (!((pars->map[i + 1][0] == ' ' || pars->map[i + 1][0] == '1') &&
		(pars->map[i + 1][1] == ' ' || pars->map[i + 1][1] == '1') &&
		(pars->map[i][1] == ' ' || pars->map[i][1] == '1')))
			f = 1;
	}
	else if (pars->map[i][0] == ' ' && i == pars->height - 1)
	{
		if (!((pars->map[i - 1][0] == ' ' || pars->map[i - 1][0] == '1') &&
		(pars->map[i - 1][1] == ' ' || pars->map[i - 1][1] == '1') &&
		(pars->map[i][1] == ' ' || pars->map[i][1] == '1')))
			f = 1;
	}
	return (f);
}
