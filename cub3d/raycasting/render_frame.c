/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:34:20 by slarrana          #+#    #+#             */
/*   Updated: 2021/02/01 20:16:09 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

double	absolute(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

void	ft_map(t_vars *vars, t_pars *pars)
{
	int i;

	vars->map = (char **)malloc(pars->height * sizeof(char *));
	i = 0;
	while (i < pars->height)
	{
		vars->map[i] = ft_strdup(pars->map[i]);
		free(pars->map[i]);
		i++;
	}
	free(pars->map);
}

int		destroy_win(t_vars *vars)
{
	int i;

	i = 0;
	while (i < vars->map_height)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	free(vars->zbuffer);
	free(vars->sprite);
	exit(0);
}

int		render_next_frame(t_vars *vars)
{
	if (vars->up == 0 && vars->down == 0 && vars->right == 0 && vars->left == 0
			&& vars->key_d == 0 && vars->key_a == 0 && vars->frame == 1)
		return (0);
	move_press(vars);
	vars->imagen.img = mlx_new_image(vars->mlx, vars->x, vars->y);
	vars->imagen.addr = (unsigned int *)mlx_get_data_addr(vars->imagen.img,
		&vars->imagen.bits, &vars->imagen.line_length, &vars->imagen.endian);
	vars->i = 0;
	while (vars->i < vars->x)
		ft_calculate(vars);
	vars->color = (int *)mlx_get_data_addr(vars->column.img,
		&vars->column.bits, &vars->column.line_length, &vars->column.endian);
	calculate_distance(vars);
	sort_sprite(vars);
	calculate_sprite(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imagen.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->imagen.img);
	vars->frame = 1;
	return (0);
}
