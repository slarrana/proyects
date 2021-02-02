/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:07:50 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 18:07:56 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	last_line_arist(t_pars *pars, int i, int f)
{
	if (!((pars->map[pars->height - 1][i - 1] == ' ' |
	pars->map[pars->height - 1][i - 1] == '1') &&
	(pars->map[pars->height - 1][i + 1] == ' ' ||
	pars->map[pars->height - 1][i + 1] == '1') &&
	(pars->map[pars->height - 2][i - 1] == ' ' ||
	pars->map[pars->height - 2][i - 1] == '1') &&
	(pars->map[pars->height - 2][i + 1] == ' ' ||
	pars->map[pars->height - 2][i + 1] == '1') &&
	(pars->map[pars->height - 2][i] == ' ' ||
	pars->map[pars->height - 2][i] == '1')))
		f = 1;
	return (f);
}

static int	last_line_left(t_pars *pars, int i, int f)
{
	if (!((pars->map[pars->height - 1][i + 1] == ' ' ||
	pars->map[pars->height - 1][i + 1] == '1') &&
	(pars->map[pars->height - 2][i + 1] == ' ' ||
	pars->map[pars->height - 2][i + 1] == '1') &&
	(pars->map[pars->height - 2][i] == ' ' ||
	pars->map[pars->height - 2][i] == '1')))
		f = 1;
	return (f);
}

int			check_last_line(t_pars *pars, int i, int f)
{
	if (pars->map[pars->height - 1][i] != ' ' &&
			pars->map[pars->height - 1][i] != '1')
		f = 1;
	else if (pars->map[pars->height - 1][i] == ' ' &&
		i > 0 && i < pars->width - 1)
		f = last_line_arist(pars, i, f);
	else if (pars->map[pars->height - 1][i] == ' ' && i == 0)
		f = last_line_left(pars, i, f);
	else if (pars->map[pars->height - 1][i] == ' ' && i == pars->width - 1)
	{
		if (!((pars->map[pars->height - 1][i - 1] == ' ' ||
		pars->map[pars->height - 1][i - 1] == '1') &&
		(pars->map[pars->height - 2][i - 1] == ' ' ||
		pars->map[pars->height - 2][i - 1] == '1') &&
		(pars->map[pars->height - 2][i] == ' ' ||
		pars->map[pars->height - 2][i] == '1')))
			f = 1;
	}
	return (f);
}
