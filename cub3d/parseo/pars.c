/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:22:16 by slarrana          #+#    #+#             */
/*   Updated: 2021/02/01 17:26:25 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	error_args(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

void		check_args(int argc, char **argv, t_pars *pars)
{
	if (argc < 2 || argc > 3)
		error_args("Error\nNumero de argumentos erroneo\n");
	if (argc == 3)
	{
		pars->save = 0;
		if ((ft_strncmp(argv[2], "--save", 7)))
			error_args("Eror\nSegundo argumento erroneo\n");
		else
			pars->save = 1;
	}
	if (check_cub(argv[1]) == -1)
		error_args("Error\nExtension del archivo incorrecta\n");
	if (argc == 2 || argc == 3)
	{
		if ((pars->fd = open(argv[1], O_RDONLY)) == -1)
			error_args("Error\nEl archivo no existe\n");
	}
}

void		ft_width_height(t_pars *pars)
{
	pars->flag = 0;
	while (pars->flag == 0)
	{
		if (get_next_line(pars->fd, &pars->str) == 0)
			pars->flag = 1;
		if ((int)ft_strlen(pars->str) > pars->width)
			pars->width = ft_strlen(pars->str);
		if (pars->str[0] == '\0')
		{
			free(pars->str);
			break ;
		}
		pars->height++;
		free(pars->str);
	}
	close(pars->fd);
}

void		ft_parse(t_pars *pars, int argc, char **argv)
{
	check_args(argc, argv, pars);
	initializate(pars);
	pars->n = 0;
	ft_readfd(pars, pars->str, pars->fd);
	if (check_variables(pars) == -1)
	{
		close(pars->fd);
		exit(-1);
	}
	pars->floor_rgb = ft_rgb(pars->floor[0], pars->floor[1], pars->floor[2]);
	pars->sky_rgb = ft_rgb(pars->sky[0], pars->sky[1], pars->sky[2]);
	ft_width_height(pars);
	ft_maping(pars, argv[1]);
	check_map(pars, 0, 0, 0);
	ubication(pars);
	check_space(pars);
	check_perimet(pars);
}
