/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:34:51 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/06 15:34:53 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	calculate_distance(t_vars *vars)
{
	int i;

	i = vars->count_sprites;
	while (i-- > 0)
		vars->sprite[i].distance = ((vars->pos_x - vars->sprite[i].coord_x) *
		(vars->pos_x - vars->sprite[i].coord_x) +
		(vars->pos_y - vars->sprite[i].coord_y) *
		(vars->pos_y - vars->sprite[i].coord_y));
}

void	sort_sprite(t_vars *vars)
{
	t_sprite	tmp;
	int			i;
	int			j;

	j = vars->count_sprites / 2 + 1;
	while (j > 0)
	{
		i = 0;
		while (i < vars->count_sprites - 1)
		{
			if (vars->sprite[i].distance >
			vars->sprite[i + 1].distance)
			{
				tmp = vars->sprite[i];
				vars->sprite[i] = vars->sprite[i + 1];
				vars->sprite[i + 1] = tmp;
			}
			i++;
		}
		j--;
	}
}

void	ft_save_sprite(t_vars *vars)
{
	int	x;
	int	y;
	int	i;

	x = 1;
	i = 0;
	while (x < vars->map_height)
	{
		y = 0;
		while (y < vars->map_width)
		{
			if (vars->map[x][y] == '2')
			{
				vars->sprite[i].coord_x = x;
				vars->sprite[i].coord_y = y;
				i++;
			}
			y++;
		}
		x++;
	}
}

void	count_sprite(t_vars *vars)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	while (x < vars->map_height)
	{
		y = 0;
		while (y < vars->map_width)
		{
			if (vars->map[x][y] == '2')
				i++;
			y++;
		}
		x++;
	}
	vars->count_sprites = i;
	vars->sprite = (t_sprite *)malloc(i * sizeof(t_sprite));
	ft_save_sprite(vars);
}

void	draw_sprite(int color, t_vars *vars)
{
	int	sprite;
	int	i;
	int	d;

	sprite = vars->draw_startx - 1;
	while (++sprite < vars->draw_endx)
	{
		vars->tex_x = (int)(256 * (sprite - (-vars->sprite_width
		/ 2 + vars->sprite_screenx)) * vars->column.width
		/ vars->sprite_width) / 256;
		if (vars->transform_y > 0 && sprite > 0 &&
		sprite < vars->x && vars->transform_y < vars->zbuffer[sprite])
		{
			i = vars->draw_starty - 1;
			while (++i < vars->draw_endy)
			{
				d = (i) * 256 - vars->y * 128 + vars->sprite_height * 128;
				vars->tex_y = ((d * 64) / vars->sprite_height) / 256;
				color =
				(unsigned int)vars->color[64 * vars->tex_y + vars->tex_x];
				if ((color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(&vars->imagen, sprite, i, color);
			}
		}
	}
}
