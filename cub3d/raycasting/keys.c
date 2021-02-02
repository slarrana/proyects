/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:33:06 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/06 15:33:07 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int		key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
		destroy_win(vars);
	if (keycode == 0)
		vars->key_a = 1;
	if (keycode == 2)
		vars->key_d = 1;
	if (keycode == 125 || keycode == 1)
		vars->down = 1;
	if (keycode == 126 || keycode == 13)
		vars->up = 1;
	if (keycode == 124)
		vars->right = 1;
	if (keycode == 123)
		vars->left = 1;
	return (0);
}

int		key_release(int keycode, t_vars *vars)
{
	if (keycode == 0)
		vars->key_a = 0;
	if (keycode == 2)
		vars->key_d = 0;
	if (keycode == 125 || keycode == 1)
		vars->down = 0;
	if (keycode == 126 || keycode == 13)
		vars->up = 0;
	if (keycode == 124)
		vars->right = 0;
	if (keycode == 123)
		vars->left = 0;
	return (0);
}

void	move_press(t_vars *vars)
{
	if (vars->key_a == 1)
		ft_move_left(vars);
	if (vars->key_d == 1)
		ft_move_right(vars);
	if (vars->down == 1)
		ft_move_down(vars);
	if (vars->up == 1)
		ft_move_up(vars);
	if (vars->right == 1)
		ft_rot_right(vars);
	if (vars->left == 1)
		ft_rot_left(vars);
}
