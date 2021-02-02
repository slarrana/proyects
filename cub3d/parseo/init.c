/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:14:30 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 17:14:38 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	map_error(t_pars *pars, char *str)
{
	ft_putstr_fd(str, 2);
	free_memory(pars);
	free_map(pars);
	exit(-1);
}

void	advance_space(char *str, t_pars *pars)
{
	while (str[pars->i] == ' ' && str[pars->i] != '\0')
		pars->i++;
}

int		check_cub(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_substr(str, ft_strlen(str) - 4, ft_strlen(str));
	if (ft_strncmp(tmp, ".cub", 4) != 0)
		i = -1;
	free(tmp);
	return (i);
}

void	repe(t_pars *pars)
{
	ft_putstr_fd("Error\nElemento repetido\n", 2);
	free_memory(pars);
	exit(-1);
}

void	initializate(t_pars *pars)
{
	pars->north_path = ft_strdup("");
	pars->north_south = ft_strdup("");
	pars->north_east = ft_strdup("");
	pars->north_weast = ft_strdup("");
	pars->path_sprite = ft_strdup("");
	pars->pos_x = 0;
	pars->pos_y = 0;
	pars->x = -1;
	pars->y = -1;
	pars->floor[0] = -1;
	pars->floor[1] = -1;
	pars->floor[2] = -1;
	pars->sky[0] = -1;
	pars->sky[1] = -1;
	pars->sky[2] = -1;
	pars->height = 0;
	pars->width = 0;
}
