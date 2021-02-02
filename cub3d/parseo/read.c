/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:49:49 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 17:51:53 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	ft_resolution(t_pars *pars, char *str)
{
	if (pars->x == -1 && pars->y == -1)
	{
		pars->i++;
		advance_space(str, pars);
		pars->x = ft_atoi(&str[pars->i]);
		while (str[pars->i] >= '0' && str[pars->i] <= '9')
			pars->i++;
		advance_space(str, pars);
		invalid_character(str, pars);
		pars->y = ft_atoi(&str[pars->i]);
		while (str[pars->i] >= '0' && str[pars->i] <= '9')
			pars->i++;
		invalid_character(str, pars);
	}
	else
		repe(pars);
}

int		ft_start_map(t_pars *pars, char *str)
{
	pars->width = (int)ft_strlen(str);
	pars->height = 1;
	free(str);
	return (1);
}

void	ft_error_line(t_pars *pars, char *str, int fd)
{
	ft_putstr_fd("Error\nLinea Invalida\n", 2);
	free(str);
	close(fd);
	free_memory(pars);
	exit(-1);
}

int		check_ifs(t_pars *pars, char *str, int fd)
{
	if (str[pars->i] == 'R')
		ft_resolution(pars, str);
	else if (str[pars->i] == 'N' && str[pars->i + 1] == 'O')
		ft_path_no(pars, str);
	else if (str[pars->i] == 'S' && str[pars->i + 1] == 'O')
		ft_path_so(pars, str);
	else if (str[pars->i] == 'W' && str[pars->i + 1] == 'E')
		ft_path_we(pars, str);
	else if (str[pars->i] == 'E' && str[pars->i + 1] == 'A')
		ft_path_ea(pars, str);
	else if (str[pars->i] == 'S' && str[pars->i + 1] == ' ')
		ft_path_sprite(pars, str);
	else if (str[pars->i] == 'F')
		ft_floor(pars, str);
	else if (str[pars->i] == 'C')
		ft_sky(pars, str);
	else if (str[pars->i] == '1' || str[pars->i] == '0' || str[pars->i] == '2'
		|| str[pars->i] == 'S' || str[pars->i] == 'N' || str[pars->i] == 'O'
		|| str[pars->i] == 'E')
		return (ft_start_map(pars, str));
	else if (str[0] != '\0')
		ft_error_line(pars, str, fd);
	return (0);
}

void	ft_readfd(t_pars *pars, char *str, int fd)
{
	int i;

	pars->flag = 0;
	while ((i = get_next_line(fd, &str)))
	{
		if (i == 0)
			pars->flag = 1;
		pars->i = 0;
		advance_space(str, pars);
		pars->flag = check_ifs(pars, str, fd);
		if (pars->flag == 1)
			break ;
		free(str);
		pars->n++;
	}
}
