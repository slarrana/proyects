/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:51:14 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/06 16:51:23 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	pos_norte(t_pars *pars)
{
	pars->dir_x = -1;
	pars->dir_y = 0;
	pars->plane_x = 0;
	pars->plane_y = 0.66;
}

static void	pos_sur(t_pars *pars)
{
	pars->dir_x = 1;
	pars->dir_y = 0;
	pars->plane_x = 0;
	pars->plane_y = -0.66;
}

static void	pos_este(t_pars *pars)
{
	pars->dir_x = 0;
	pars->dir_y = 1;
	pars->plane_x = 0.66;
	pars->plane_y = 0;
}

static void	pos_oeste(t_pars *pars)
{
	pars->dir_x = 0;
	pars->dir_y = -1;
	pars->plane_x = -0.66;
	pars->plane_y = 0;
}

void		ft_start_pos(t_pars *pars, int i, int j)
{
	pars->pos_x = i;
	pars->pos_y = j;
	if (pars->map[i][j] == 'N')
		pos_norte(pars);
	else if (pars->map[i][j] == 'S')
		pos_sur(pars);
	else if (pars->map[i][j] == 'E')
		pos_este(pars);
	else
		pos_oeste(pars);
	pars->map[i][j] = '0';
}
