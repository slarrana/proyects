/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:32:38 by slarrana          #+#    #+#             */
/*   Updated: 2021/02/01 20:16:37 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	texture_error(t_vars *vars, t_pars *pars)
{
	ft_putstr_fd("Error\nPath Invalido\n", 2);
	free_memory(pars);
	free(vars->zbuffer);
	exit(0);
}

void		initialize_variable(t_vars *vars, t_pars *pars)
{
	ft_map(vars, pars);
	vars->map_height = pars->height;
	vars->map_width = pars->width;
	vars->i = 0;
	vars->pos_x = (double)pars->pos_x + 0.5;
	vars->pos_y = (double)pars->pos_y + 0.5;
	vars->dir_x = pars->dir_x;
	vars->dir_y = pars->dir_y;
	vars->plane_x = pars->plane_x;
	vars->plane_y = pars->plane_y;
	vars->up = 0;
	vars->down = 0;
	vars->right = 0;
	vars->left = 0;
	vars->key_a = 0;
	vars->key_d = 0;
	vars->move_speed = 0.4;
	vars->rot_speed = 0.05;
	vars->color_floor = pars->floor_rgb;
	vars->color_sky = pars->sky_rgb;
	vars->frame = 0;
}

void		load_texture(t_vars *vars, t_pars *pars)
{
	if (!(vars->tex1.img = mlx_xpm_file_to_image(vars->mlx,
		pars->north_path, &vars->tex1.width, &vars->tex1.height)))
		texture_error(vars, pars);
	if (!(vars->tex2.img = mlx_xpm_file_to_image(vars->mlx,
		pars->north_south, &vars->tex2.width, &vars->tex2.height)))
		texture_error(vars, pars);
	if (!(vars->tex3.img = mlx_xpm_file_to_image(vars->mlx,
		pars->north_east, &vars->tex3.width, &vars->tex3.height)))
		texture_error(vars, pars);
	if (!(vars->tex4.img = mlx_xpm_file_to_image(vars->mlx,
		pars->north_weast, &vars->tex4.width, &vars->tex4.height)))
		texture_error(vars, pars);
	if (!(vars->column.img = mlx_xpm_file_to_image(vars->mlx,
		pars->path_sprite, &vars->column.width, &vars->column.height)))
		texture_error(vars, pars);
	free_memory(pars);
}
