/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:33:19 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/06 15:34:06 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	ft_move_left(t_vars *vars)
{
	if (vars->map[(int)(vars->pos_x - vars->dir_y *
			vars->move_speed)][(int)vars->pos_y] == '0')
		vars->pos_x -= vars->dir_y * vars->move_speed;
	if (vars->map[(int)vars->pos_x][(int)(vars->pos_y +
			vars->dir_x * vars->move_speed)] == '0')
		vars->pos_y += vars->dir_x * vars->move_speed;
}

void	ft_move_right(t_vars *vars)
{
	if (vars->map[(int)(vars->pos_x + vars->dir_y *
			vars->move_speed)][(int)vars->pos_y] == '0')
		vars->pos_x += vars->dir_y * vars->move_speed;
	if (vars->map[(int)vars->pos_x][(int)(vars->pos_y -
			vars->dir_x * vars->move_speed)] == '0')
		vars->pos_y -= vars->dir_x * vars->move_speed;
}

void	ft_move_down(t_vars *vars)
{
	if (vars->map[(int)(vars->pos_x - vars->dir_x *
			vars->move_speed)][(int)vars->pos_y] == '0')
		vars->pos_x -= vars->dir_x * vars->move_speed;
	if (vars->map[(int)vars->pos_x][(int)(vars->pos_y -
			vars->dir_y * vars->move_speed)] == '0')
		vars->pos_y -= vars->dir_y * vars->move_speed;
}

void	ft_move_up(t_vars *vars)
{
	if (vars->map[(int)(vars->pos_x + vars->dir_x *
			vars->move_speed)][(int)vars->pos_y] == '0')
		vars->pos_x += vars->dir_x * vars->move_speed;
	if (vars->map[(int)vars->pos_x][(int)(vars->pos_y +
			vars->dir_y * vars->move_speed)] == '0')
		vars->pos_y += vars->dir_y * vars->move_speed;
}
