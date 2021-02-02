/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:31:27 by slarrana          #+#    #+#             */
/*   Updated: 2021/02/01 15:57:27 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		my_mlx_pixel_put(t_img *imagen, int x, int y, int color)
{
	char	*dst;

	dst = (char *)(imagen->addr + (y * imagen->line_length + x *
		(imagen->bits / 8)));
	*(unsigned int*)dst = color;
	return (0);
}

void	draw_floor_sky(int x, t_img *img, t_vars *vars)
{
	int i;

	i = 0;
	while (i < vars->draw_start)
	{
		my_mlx_pixel_put(img, x, i, vars->color_sky);
		i++;
	}
	i = vars->draw_end + 1;
	while (i < vars->y && i > 0)
	{
		my_mlx_pixel_put(img, x, i, vars->color_floor);
		i++;
	}
}

void	draw_line(int x, int color, t_img *img, t_vars *vars)
{
	int	y_start;
	int	y_end;

	y_start = vars->draw_start;
	y_end = vars->draw_end;
	vars->step = 1.0 * vars->tex_height / vars->line_height;
	vars->tex_pos = (y_start - vars->y / 2 +
			vars->line_height / 2) * vars->step;
	while (y_start < y_end)
	{
		vars->tex_y = (int)vars->tex_pos;
		vars->tex_pos += vars->step;
		color =
			(unsigned int)vars->color[(vars->tex_height)
			* vars->tex_y + vars->tex_x];
		my_mlx_pixel_put(img, x, y_start, color);
		y_start++;
	}
}
