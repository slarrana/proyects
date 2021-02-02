/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:09:24 by slarrana          #+#    #+#             */
/*   Updated: 2021/02/01 18:40:13 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*get_path(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	return (ft_substr(str, 0, i));
}

int		ft_error_variables(t_pars *pars, char *str)
{
	free_memory(pars);
	ft_putstr_fd(str, 2);
	return (-1);
}

int		check_variables(t_pars *pars)
{
	if (pars->x == -1 || pars->y == -1 || pars->x == 0 || pars->y == 0)
		return (ft_error_variables(pars, "Error\nResolucion Invalida\n"));
	if (pars->floor[0] < 0 || pars->floor[0] > 255 || pars->floor[1] < 0
	|| pars->floor[1] > 255 || pars->floor[2] < 0 || pars->floor[2] > 255)
		return (ft_error_variables(pars, "Error\nColor Invalido\n"));
	if (pars->sky[0] < 0 || pars->sky[0] > 255 || pars->sky[1] < 0
	|| pars->sky[1] > 255 || pars->sky[2] < 0 || pars->sky[2] > 255)
		return (ft_error_variables(pars, "Error\nColor Invalido\n"));
	if (pars->north_path[0] == '\0' || pars->north_south[0] == '\0'
	|| pars->north_weast[0] == '\0' || pars->north_east[0] == '\0'
	|| pars->path_sprite[0] == '\0')
		return (ft_error_variables(pars, "Error\nPath Invalido\n"));
	if (pars->height == 0)
		return (ft_error_variables(pars, "Error\nMapa Invalido\n"));
	return (0);
}

void	check_map(t_pars *pars, int i, int j, int p)
{
	while (i < pars->height)
	{
		j = 0;
		while (pars->map[i][j] != '\0')
		{
			if (pars->map[i][j] != '1' && pars->map[i][j] != '2'
				&& pars->map[i][j] != '0'
				&& pars->map[i][j] != 'N' && pars->map[i][j] != 'S'
				&& pars->map[i][j] != 'E'
				&& pars->map[i][j] != 'W' && pars->map[i][j] != ' ')
				map_error(pars, "Error\nCaracteres Invalidos en Mapa\n");
			if (pars->map[i][j] == 'N' || pars->map[i][j] == 'S'
				|| pars->map[i][j] == 'E' || pars->map[i][j] == 'W')
				p++;
			j++;
		}
		i++;
	}
	if (p != 1)
		map_error(pars, "Error\nPosicion no valida\n");
}
