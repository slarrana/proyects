/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:13:56 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 17:14:13 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

unsigned int	ft_rgb(int red, int green, int blue)
{
	unsigned int	rgb;

	rgb = (256 * 256 * red) + (256 * green) + blue;
	return (rgb);
}

void			ft_floor0(t_pars *pars, char *str)
{
	pars->i++;
	advance_space(str, pars);
	invalid_character(str, pars);
	pars->floor[0] = ft_atoi(&str[pars->i]);
	while (str[pars->i] >= '0' && str[pars->i] <= '9')
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

void			ft_floor1(t_pars *pars, char *str)
{
	pars->floor[1] = ft_atoi(&str[pars->i]);
	while (str[pars->i] >= '0' && str[pars->i] <= '9')
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

void			ft_floor2(t_pars *pars, char *str)
{
	pars->floor[2] = ft_atoi(&str[pars->i]);
	if (!(str[pars->i] >= '0' && str[pars->i] <= '9'))
	{
		ft_putstr_fd("Error\nColor Invalido\n", 2);
		free_memory(pars);
		exit(-1);
	}
	while (str[pars->i] >= '0' && str[pars->i] <= '9')
		pars->i++;
	invalid_character(str, pars);
}

void			ft_floor(t_pars *pars, char *str)
{
	if (pars->floor[0] == -1 && pars->floor[1] == -1 && pars->floor[2] == -1)
	{
		ft_floor0(pars, str);
		ft_floor1(pars, str);
		ft_floor2(pars, str);
	}
	else
		repe(pars);
}
