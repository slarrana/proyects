/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:50:53 by slarrana          #+#    #+#             */
/*   Updated: 2021/02/01 16:19:51 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	create_img(t_vars *vars)
{
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
	create_bmp(vars);
}
