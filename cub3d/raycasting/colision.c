/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colision.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:31:10 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/06 15:31:15 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ft_hit(t_vars *vars)
{
	while (vars->hit == 0)
	{
		if (vars->side_distx < vars->side_disty && vars->map_x > 0)
		{
			vars->side_distx += vars->delta_distx;
			vars->map_x += vars->step_x;
			vars->side = 0;
		}
		else
		{
			vars->side_disty += vars->delta_disty;
			vars->map_y += vars->step_y;
			vars->side = 1;
		}
		if (vars->map[vars->map_x][vars->map_y] == '1')
			vars->hit = 1;
	}
}

void	calculate_side(t_vars *vars)
{
	if (vars->ray_dirx < 0)
	{
		vars->step_x = -1;
		vars->side_distx = (vars->pos_x - vars->map_x)
			* vars->delta_distx;
	}
	else
	{
		vars->step_x = 1;
		vars->side_distx = (vars->map_x + 1.0 - vars->pos_x)
			* vars->delta_distx;
	}
	if (vars->ray_diry < 0)
	{
		vars->step_y = -1;
		vars->side_disty = (vars->pos_y - vars->map_y)
			* vars->delta_disty;
	}
	else
	{
		vars->step_y = 1;
		vars->side_disty = (vars->map_y + 1.0 - vars->pos_y)
			* vars->delta_disty;
	}
	ft_hit(vars);
}
