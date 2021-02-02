/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:27:47 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 17:27:48 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_path_no(t_pars *pars, char *str)
{
	if (pars->north_path[0] == '\0')
	{
		pars->i += 2;
		advance_space(str, pars);
		free(pars->north_path);
		pars->north_path = get_path(&str[pars->i]);
		check_north_path(pars);
	}
	else
		repe(pars);
}

void	ft_path_so(t_pars *pars, char *str)
{
	if (pars->north_south[0] == '\0')
	{
		pars->i += 2;
		advance_space(str, pars);
		free(pars->north_south);
		pars->north_south = get_path(&str[pars->i]);
		check_north_south(pars);
	}
	else
		repe(pars);
}

void	ft_path_we(t_pars *pars, char *str)
{
	if (pars->north_weast[0] == '\0')
	{
		pars->i += 2;
		advance_space(str, pars);
		free(pars->north_weast);
		pars->north_weast = get_path(&str[pars->i]);
		check_north_weast(pars);
	}
	else
		repe(pars);
}

void	ft_path_ea(t_pars *pars, char *str)
{
	if (pars->north_east[0] == '\0')
	{
		pars->i += 2;
		advance_space(str, pars);
		free(pars->north_east);
		pars->north_east = get_path(&str[pars->i]);
		check_north_east(pars);
	}
	else
		repe(pars);
}

void	ft_path_sprite(t_pars *pars, char *str)
{
	if (pars->path_sprite[0] == '\0')
	{
		pars->i++;
		advance_space(str, pars);
		free(pars->path_sprite);
		pars->path_sprite = get_path(&str[pars->i]);
		check_path_sprite(pars);
	}
	else
		repe(pars);
}
