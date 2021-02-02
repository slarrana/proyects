/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:15:45 by slarrana          #+#    #+#             */
/*   Updated: 2021/02/01 17:26:08 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	ft_read_fd(t_pars *pars)
{
	while (pars->j < pars->height)
	{
		pars->i = 0;
		if (get_next_line(pars->fd, &pars->str) == 0)
			pars->flag = 1;
		if (pars->map_start >= pars->n && pars->j < pars->height)
			save_map(pars->str, pars, pars->j++);
		free(pars->str);
		pars->map_start++;
	}
	while (get_next_line(pars->fd, &pars->str))
	{
		if (pars->str[0] != '\0')
		{
			ft_putstr_fd(
			"Error\nCaracteres Invalido despues del Mapa\n", 2);
			exit(0);
		}
		free(pars->str);
	}
}

void		free_memory(t_pars *pars)
{
	free(pars->north_path);
	free(pars->north_south);
	free(pars->north_east);
	free(pars->north_weast);
	free(pars->path_sprite);
}

void		free_map(t_pars *pars)
{
	int	i;

	i = 0;
	while (i < pars->height)
	{
		free(pars->map[i]);
		pars->map[i] = NULL;
		i++;
	}
	free(pars->map);
}

void		save_map(char *str, t_pars *pars, int i)
{
	int		j;
	char	*tmp;
	char	*line;

	j = ft_strlen(str);
	line = ft_strdup(str);
	while (j < pars->width)
	{
		tmp = ft_strjoin(line, " ");
		free(line);
		line = ft_strdup(tmp);
		free(tmp);
		j++;
	}
	pars->map[i] = ft_strdup(line);
	free(line);
}

void		ft_maping(t_pars *pars, char *str)
{
	pars->map = (char **)ft_calloc((pars->height), sizeof(char *));
	pars->fd = open(str, O_RDONLY);
	pars->flag = 0;
	pars->j = 0;
	pars->map_start = 0;
	ft_read_fd(pars);
	close(pars->fd);
}
