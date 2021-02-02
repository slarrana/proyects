/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:11:41 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 17:13:30 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_north_path(t_pars *pars)
{
	int i;

	i = 0;
	if (!(strncmp(pars->north_path, pars->north_south,
			ft_strlen(pars->north_path) + 2)))
		i = 1;
	if (!(strncmp(pars->north_path, pars->north_east,
			ft_strlen(pars->north_path) + 2)))
		i = 1;
	if (!(strncmp(pars->north_path, pars->north_weast,
			ft_strlen(pars->north_path) + 2)))
		i = 1;
	if (i == 1)
	{
		ft_putstr_fd("Error\nPath Invalido\n", 2);
		free_memory(pars);
		exit(-1);
	}
}

void	check_north_east(t_pars *pars)
{
	int i;

	i = 0;
	if (!(strncmp(pars->north_east, pars->north_south,
			ft_strlen(pars->north_east) + 2)))
		i = 1;
	if (!(strncmp(pars->north_east, pars->north_path,
			ft_strlen(pars->north_east) + 2)))
		i = 1;
	if (!(strncmp(pars->north_east, pars->north_weast,
			ft_strlen(pars->north_east) + 2)))
		i = 1;
	if (i == 1)
	{
		ft_putstr_fd("Error\nPath Invalido\n", 2);
		free_memory(pars);
		exit(-1);
	}
}

void	check_north_south(t_pars *pars)
{
	int i;

	i = 0;
	if (!(strncmp(pars->north_south, pars->north_path,
			ft_strlen(pars->north_south) + 2)))
		i = 1;
	if (!(strncmp(pars->north_south, pars->north_east,
			ft_strlen(pars->north_south) + 2)))
		i = 1;
	if (!(strncmp(pars->north_south, pars->north_weast,
			ft_strlen(pars->north_south) + 2)))
		i = 1;
	if (i == 1)
	{
		ft_putstr_fd("Error\nPath Invalido\n", 2);
		free_memory(pars);
		exit(-1);
	}
}

void	check_north_weast(t_pars *pars)
{
	int i;

	i = 0;
	if (!(strncmp(pars->north_weast, pars->north_south,
			ft_strlen(pars->north_weast) + 2)))
		i = 1;
	if (!(strncmp(pars->north_weast, pars->north_east,
			ft_strlen(pars->north_weast) + 2)))
		i = 1;
	if (!(strncmp(pars->north_weast, pars->north_path,
			ft_strlen(pars->north_weast) + 2)))
		i = 1;
	if (i == 1)
	{
		ft_putstr_fd("Error\nPath Invalido\n", 2);
		free_memory(pars);
		exit(-1);
	}
}

void	check_path_sprite(t_pars *pars)
{
	int i;

	i = 0;
	if (!(strncmp(pars->path_sprite, pars->north_south,
			ft_strlen(pars->path_sprite) + 2)))
		i = 1;
	if (!(strncmp(pars->path_sprite, pars->north_east,
			ft_strlen(pars->path_sprite) + 2)))
		i = 1;
	if (!(strncmp(pars->path_sprite, pars->north_path,
			ft_strlen(pars->path_sprite) + 2)))
		i = 1;
	if (!(strncmp(pars->path_sprite, pars->north_weast,
			ft_strlen(pars->path_sprite) + 2)))
		i = 1;
	if (i == 1)
	{
		ft_putstr_fd("Error\nPath Invalido\n", 2);
		free_memory(pars);
		exit(-1);
	}
}
