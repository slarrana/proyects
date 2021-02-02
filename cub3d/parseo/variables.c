/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:54:20 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 17:54:40 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ubication(t_pars *pars)
{
	int	i;
	int	j;

	i = 0;
	while (i < pars->height)
	{
		j = 0;
		while (pars->map[i][j] != '\0')
		{
			if (pars->map[i][j] == 'N' || pars->map[i][j] == 'S'
			|| pars->map[i][j] == 'E' || pars->map[i][j] == 'W')
				ft_start_pos(pars, i, j);
			j++;
		}
		i++;
	}
	if (pars->pos_x == 0 || pars->pos_y == 0)
	{
		ft_putstr_fd("Error\nEl jugador no esta encerrado entre muros\n", 2);
		free_memory(pars);
		free_map(pars);
		exit(-1);
	}
}

void	invalid_character(char *str, t_pars *pars)
{
	if (!((str[pars->i] >= '0' && str[pars->i] <= '9') || str[pars->i] == '\0'))
	{
		free_memory(pars);
		ft_putstr_fd("Error\nValor Invalido\n", 2);
		exit(0);
	}
}

void	ft_control_map(t_pars *pars, int i, int j)
{
	if (!((pars->map[i][j + 1] == ' ' || pars->map[i][j + 1] == '1') &&
		(pars->map[i][j - 1] == ' ' || pars->map[i][j - 1] == '1') &&
		(pars->map[i + 1][j] == ' ' || pars->map[i + 1][j] == '1') &&
		(pars->map[i - 1][j] == ' ' || pars->map[i - 1][j] == '1') &&
		(pars->map[i + 1][j + 1] == ' ' || pars->map[i + 1][j + 1] == '1') &&
		(pars->map[i - 1][j - 1] == ' ' || pars->map[i - 1][j - 1] == '1') &&
		(pars->map[i - 1][j + 1] == ' ' || pars->map[i - 1][j + 1] == '1') &&
		(pars->map[i + 1][j - 1] == ' ' || pars->map[i + 1][j - 1] == '1')))
		map_error(pars, "Error\nMapa Invalido\n");
}

void	check_space(t_pars *pars)
{
	int	i;
	int	j;

	i = 1;
	while (i < pars->height - 1)
	{
		j = 1;
		while (j < pars->width - 1)
		{
			if (pars->map[i][j] == ' ')
				ft_control_map(pars, i, j);
			j++;
		}
		i++;
	}
}
