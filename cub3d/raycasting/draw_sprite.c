/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:32:08 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/06 15:32:09 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	calculate_sprite(t_vars *vars)
{
	int i;

	i = vars->count_sprites;
	while (i-- > 0)
		ft_draw_sprite(vars, i);
}

void	ft_draw_sprite(t_vars *vars, int i)
{
	vars->sprite[i].x = vars->sprite[i].coord_x - vars->pos_x + 0.5;
	vars->sprite[i].y = vars->sprite[i].coord_y - vars->pos_y + 0.5;
	vars->inv_det = 1.0 / (vars->plane_x *
			vars->dir_y - vars->dir_x * vars->plane_y);
	vars->transform_x = vars->inv_det * (vars->dir_y
			* vars->sprite[i].x - vars->dir_x * vars->sprite[i].y);
	vars->transform_y = vars->inv_det * (-vars->plane_y
			* vars->sprite[i].x + vars->plane_x * vars->sprite[i].y);
	vars->sprite_screenx = (int)((vars->x / 2)
			* (1 + vars->transform_x / vars->transform_y));
	vars->sprite_height = absolute((int)(vars->y / (vars->transform_y)));
	vars->draw_starty = -vars->sprite_height / 2 + vars->y / 2;
	if (vars->draw_starty < 0)
		vars->draw_starty = 0;
	vars->draw_endy = vars->sprite_height / 2 + vars->y / 2;
	if (vars->draw_endy >= vars->y)
		vars->draw_endy = vars->y - 1;
	vars->sprite_width = absolute((int)(vars->y / (vars->transform_y)));
	vars->draw_startx = -vars->sprite_width / 2 + vars->sprite_screenx;
	if (vars->draw_startx < 0)
		vars->draw_startx = 0;
	vars->draw_endx = vars->sprite_width / 2 + vars->sprite_screenx;
	if (vars->draw_endx >= vars->x)
		vars->draw_endx = vars->x - 1;
	draw_sprite(0, vars);
}
