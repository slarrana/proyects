/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:34:35 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/06 15:34:37 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ft_rot_right(t_vars *vars)
{
	vars->old_dirx = vars->dir_x;
	vars->dir_x = vars->dir_x * cos(-vars->rot_speed)
		- vars->dir_y * sin(-vars->rot_speed);
	vars->dir_y = vars->old_dirx * sin(-vars->rot_speed)
		+ vars->dir_y * cos(-vars->rot_speed);
	vars->old_planex = vars->plane_x;
	vars->plane_x = vars->plane_x * cos(-vars->rot_speed)
		- vars->plane_y * sin(-vars->rot_speed);
	vars->plane_y = vars->old_planex * sin(-vars->rot_speed)
		+ vars->plane_y * cos(-vars->rot_speed);
}

void	ft_rot_left(t_vars *vars)
{
	vars->old_dirx = vars->dir_x;
	vars->dir_x = vars->dir_x * cos(vars->rot_speed)
		- vars->dir_y * sin(vars->rot_speed);
	vars->dir_y = vars->old_dirx * sin(vars->rot_speed)
		+ vars->dir_y * cos(vars->rot_speed);
	vars->old_planex = vars->plane_x;
	vars->plane_x = vars->plane_x * cos(vars->rot_speed)
		- vars->plane_y * sin(vars->rot_speed);
	vars->plane_y = vars->old_planex * sin(vars->rot_speed)
		+ vars->plane_y * cos(vars->rot_speed);
}
