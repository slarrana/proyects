/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:24:35 by slarrana          #+#    #+#             */
/*   Updated: 2021/02/01 17:23:10 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parseo/parse.h"
#include "raycasting/raycasting.h"

static void	max_resolution(t_pars *pars, t_vars *vars)
{
	if (pars->x > vars->max_x || pars->x < 0)
		vars->x = vars->max_x;
	else
		vars->x = pars->x;
	if (pars->y > vars->max_y || pars->y < 0)
		vars->y = vars->max_y;
	else
		vars->y = pars->y;
}

int			main(int argc, char **argv)
{
	t_pars	pars;
	t_vars	vars;

	ft_parse(&pars, argc, argv);
	vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &vars.max_x, &vars.max_y);
	max_resolution(&pars, &vars);
	initialize_variable(&vars, &pars);
	vars.zbuffer = (double *)malloc(vars.x * sizeof(double));
	load_texture(&vars, &pars);
	count_sprite(&vars);
	if (pars.save == 1)
		create_img(&vars);
	vars.win = mlx_new_window(vars.mlx, vars.x, vars.y, "cub3d");
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 3, 1L << 1, key_release, &vars);
	mlx_hook(vars.win, 17, 0, destroy_win, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
