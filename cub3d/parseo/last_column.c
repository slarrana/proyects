/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:07:05 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 18:07:12 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	last_column_arist(t_pars *pars, int i, int f)
{
	if (!((pars->map[i - 1][pars->width - 1] == ' ' ||
	pars->map[i - 1][pars->width - 1] == '1') &&
	(pars->map[i + 1][pars->width - 1] == ' ' ||
	pars->map[i + 1][pars->width - 1] == '1') &&
	(pars->map[i - 1][pars->width - 2] == ' ' ||
	pars->map[i - 1][pars->width - 2] == '1') &&
	(pars->map[i + 1][pars->width - 2] == ' ' ||
	pars->map[i + 1][pars->width - 2] == '1') &&
	(pars->map[i][pars->width - 2] == ' ' ||
	pars->map[i][pars->width - 2] == '1')))
		f = 1;
	return (f);
}

static int	last_column_right(t_pars *pars, int i, int f)
{
	if (!((pars->map[i - 1][pars->width - 1] == ' ' ||
	pars->map[i - 1][pars->width - 1] == '1') &&
	(pars->map[i - 1][pars->width - 2] == ' ' ||
	pars->map[i - 1][pars->width - 2] == '1') &&
	(pars->map[i][pars->width - 2] == ' ' ||
	pars->map[i][pars->width - 2] == '1')))
		f = 1;
	return (f);
}

int			check_last_column(t_pars *pars, int i, int f)
{
	if (pars->map[i][pars->width - 1] != ' ' &&
			pars->map[i][pars->width - 1] != '1')
		f = 1;
	else if (pars->map[i][pars->width - 1] == ' ' &&
		i > 0 && i < pars->height - 1)
		f = last_column_arist(pars, i, f);
	else if (pars->map[i][pars->width - 1] == ' ' && i == 0)
	{
		if (!((pars->map[i + 1][pars->width - 1] == ' ' ||
		pars->map[i + 1][pars->width - 1] == '1') &&
		(pars->map[i + 1][pars->width - 2] == ' ' ||
		pars->map[i + 1][pars->width - 2] == '1') &&
		(pars->map[i][pars->width - 2] == ' ' ||
		pars->map[i][pars->width - 2] == '1')))
			f = 1;
	}
	else if (pars->map[i][pars->width - 1] == ' ' &&
		i == pars->height - 1)
		f = last_column_right(pars, i, f);
	return (f);
}
