/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:35:06 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/06 15:50:24 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void	ft_tex4(t_vars *vars)
{
	vars->color = (int *)mlx_get_data_addr(vars->tex4.img,
		&vars->tex4.bits, &vars->tex4.line_length, &vars->tex4.endian);
	vars->tex_height = vars->tex4.height;
	vars->tex_width = vars->tex4.width;
}

static void	ft_color(t_vars *vars)
{
	if (vars->side == 0 && vars->step_x == -1)
	{
		vars->color = (int *)mlx_get_data_addr(vars->tex1.img,
				&vars->tex1.bits, &vars->tex1.line_length, &vars->tex1.endian);
		vars->tex_height = vars->tex1.height;
		vars->tex_width = vars->tex1.width;
	}
	else if (vars->side == 0 && vars->step_x == 1)
	{
		vars->color = (int *)mlx_get_data_addr(vars->tex2.img,
				&vars->tex2.bits, &vars->tex2.line_length, &vars->tex2.endian);
		vars->tex_height = vars->tex2.height;
		vars->tex_width = vars->tex2.width;
	}
	else if (vars->side == 1 && vars->step_y == 1)
	{
		vars->color = (int *)mlx_get_data_addr(vars->tex3.img,
				&vars->tex3.bits, &vars->tex3.line_length, &vars->tex3.endian);
		vars->tex_height = vars->tex3.height;
		vars->tex_width = vars->tex3.width;
	}
	else if (vars->side == 1 && vars->step_y == -1)
		ft_tex4(vars);
}

void		calculate_color(t_vars *vars)
{
	if (vars->side == 0)
		vars->perp_walldist = (vars->map_x - vars->pos_x
				+ (1 - vars->step_x) / 2) / vars->ray_dirx;
	else
		vars->perp_walldist = (vars->map_y - vars->pos_y
				+ (1 - vars->step_y) / 2) / vars->ray_diry;
	vars->line_height = (int)(vars->y / vars->perp_walldist);
	vars->draw_start = -vars->line_height / 2 + vars->y / 2;
	if (vars->draw_start < 0)
		vars->draw_start = 0;
	vars->draw_end = vars->line_height / 2 + vars->y / 2;
	if (vars->draw_end >= vars->y)
		vars->draw_end = vars->y - 1;
	ft_color(vars);
}

void		ft_calculate(t_vars *vars)
{
	vars->camera_x = 2 * vars->i / (double)vars->x - 1;
	vars->ray_dirx = vars->dir_x + vars->plane_x * vars->camera_x;
	vars->ray_diry = vars->dir_y + vars->plane_y * vars->camera_x;
	vars->map_x = (int)vars->pos_x;
	vars->map_y = (int)vars->pos_y;
	vars->delta_distx = absolute(1 / vars->ray_dirx);
	vars->delta_disty = absolute(1 / vars->ray_diry);
	vars->hit = 0;
	calculate_side(vars);
	calculate_color(vars);
	if (vars->side == 0)
		vars->wall_x = vars->pos_y + vars->perp_walldist * vars->ray_diry;
	else
		vars->wall_x = vars->pos_x + vars->perp_walldist * vars->ray_dirx;
	vars->wall_x -= floor(vars->wall_x);
	vars->tex_x = (int)(vars->wall_x * (double)vars->tex_width);
	if (vars->side == 0 && vars->ray_dirx > 0)
		vars->tex_x = vars->tex_width - vars->tex_x - 1;
	if (vars->side == 1 && vars->ray_diry < 0)
		vars->tex_x = vars->tex_width - vars->tex_x - 1;
	draw_line(vars->i, 0, &vars->imagen, vars);
	draw_floor_sky(vars->i, &vars->imagen, vars);
	vars->zbuffer[vars->i] = vars->perp_walldist;
	vars->i++;
}
