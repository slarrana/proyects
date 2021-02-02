/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:53:02 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 17:54:11 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_sky0(t_pars *pars, char *str)
{
	pars->i++;
	advance_space(str, pars);
	invalid_character(str, pars);
	pars->sky[0] = ft_atoi(&str[pars->i]);
	while ((str[pars->i] >= '0' && str[pars->i] <= '9') || str[pars->i] == '-')
		pars->i++;
	advance_space(str, pars);
	if (str[pars->i] != ',')
	{
		ft_putstr_fd("Error\nColor Invalido\n", 2);
		free_memory(pars);
		exit(-1);
	}
	pars->i++;
	advance_space(str, pars);
	invalid_character(str, pars);
}

void	ft_sky1(t_pars *pars, char *str)
{
	pars->sky[1] = ft_atoi(&str[pars->i]);
	while ((str[pars->i] >= '0' && str[pars->i] <= '9') || str[pars->i] == '-')
		pars->i++;
	advance_space(str, pars);
	if (str[pars->i] != ',')
	{
		ft_putstr_fd("Error\nColor Invalido\n", 2);
		free_memory(pars);
		exit(-1);
	}
	pars->i++;
	advance_space(str, pars);
	invalid_character(str, pars);
}

void	ft_sky2(t_pars *pars, char *str)
{
	pars->sky[2] = ft_atoi(&str[pars->i]);
	if (!(str[pars->i] >= '0' && str[pars->i] <= '9'))
	{
		ft_putstr_fd("Error\nColor Invalido\n", 2);
		free_memory(pars);
		exit(-1);
	}
	while ((str[pars->i] >= '0' && str[pars->i] <= '9') || str[pars->i] == '-')
		pars->i++;
	invalid_character(str, pars);
}

void	ft_sky(t_pars *pars, char *str)
{
	if (pars->sky[0] == -1 && pars->sky[1] == -1 && pars->sky[2] == -1)
	{
		ft_sky0(pars, str);
		ft_sky1(pars, str);
		ft_sky2(pars, str);
	}
	else
		repe(pars);
}
