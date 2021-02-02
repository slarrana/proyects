/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:07:32 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 18:07:37 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	first_line_arist(t_pars *pars, int i, int f)
{
	if (!((pars->map[0][i - 1] == ' ' || pars->map[0][i - 1] == '1') &&
	(pars->map[0][i + 1] == ' ' || pars->map[0][i + 1] == '1') &&
	(pars->map[1][i - 1] == ' ' || pars->map[1][i - 1] == '1') &&
	(pars->map[1][i + 1] == ' ' || pars->map[1][i + 1] == '1') &&
	(pars->map[1][i] == ' ' || pars->map[1][i] == '1')))
		f = 1;
	return (f);
}

int			check_first_line(t_pars *pars, int i, int f)
{
	if (pars->map[0][i] != ' ' && pars->map[0][i] != '1')
		f = 1;
	else if (pars->map[0][i] == ' ' && i > 0 && i < pars->width - 1)
		f = first_line_arist(pars, i, f);
	else if (pars->map[0][i] == ' ' && i == 0)
	{
		if (!((pars->map[0][i + 1] == ' ' || pars->map[0][i + 1] == '1') &&
		(pars->map[1][i + 1] == ' ' || pars->map[1][i + 1] == '1') &&
		(pars->map[1][i] == ' ' || pars->map[1][i] == '1')))
			f = 1;
	}
	else if (pars->map[0][i] == ' ' && i == pars->width - 1)
	{
		if (!((pars->map[0][i - 1] == ' ' || pars->map[0][i - 1] == '1') &&
		(pars->map[1][i - 1] == ' ' || pars->map[1][i - 1] == '1') &&
		(pars->map[1][i] == ' ' || pars->map[1][i] == '1')))
			f = 1;
	}
	return (f);
}
