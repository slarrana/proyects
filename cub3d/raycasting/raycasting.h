/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:59:58 by slarrana          #+#    #+#             */
/*   Updated: 2021/02/01 20:16:23 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../libft/libft.h"
# include "../parseo/parse.h"
# include "../minilibx_mms_20200219/mlx.h"
# include <math.h>

typedef struct	s_img
{
	void		*img;
	void		*addr;
	int			bits;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			coord_x;
	int			coord_y;
	double		distance;
}				t_sprite;

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			map_width;
	int			map_height;
	int			keycode;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			i;
	double		camera_x;
	double		ray_dirx;
	double		ray_diry;
	int			map_x;
	int			map_y;
	double		side_distx;
	double		side_disty;
	double		delta_distx;
	double		delta_disty;
	double		perp_walldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			*color;
	double		move_speed;
	double		rot_speed;
	double		old_dirx;
	double		old_planex;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
	t_img		imagen;
	t_img		tex1;
	t_img		tex2;
	t_img		tex3;
	t_img		tex4;
	t_img		column;
	t_sprite	*sprite;
	double		*zbuffer;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			sprite_screenx;
	int			sprite_height;
	int			draw_starty;
	int			draw_endy;
	int			sprite_screeny;
	int			sprite_width;
	int			draw_startx;
	int			draw_endx;
	int			count_sprites;
	int			up;
	int			down;
	int			right;
	int			left;
	int			key_d;
	int			key_a;
	char		**map;
	int			tex_height;
	int			tex_width;
	int			color_floor;
	int			color_sky;
	int			max_x;
	int			max_y;
	int			frame;
}				t_vars;

double			absolute(double num);
void			calculate_distance(t_vars *vars);
void			sort_sprite(t_vars *vars);
void			ft_save_sprite(t_vars *vars);
void			count_sprite(t_vars *vars);
int				my_mlx_pixel_put(t_img *imagen, int x, int y, int color);
void			draw_sprite(int color, t_vars *vars);
void			draw_floor_sky(int x, t_img *img, t_vars *vars);
void			draw_line(int x, int color, t_img *img, t_vars *vars);
int				key_press(int keycode, t_vars *vars);
int				key_release(int keycode, t_vars *vars);
void			ft_move_left(t_vars *vars);
void			ft_move_right(t_vars *vars);
void			ft_move_down(t_vars *vars);
void			ft_move_up(t_vars *vars);
void			ft_rot_right(t_vars *vars);
void			ft_rot_left(t_vars *vars);
void			move_press(t_vars *vars);
void			ft_hit(t_vars *vars);
void			calculate_side(t_vars *vars);
void			calculate_color(t_vars *vars);
void			ft_draw_sprite(t_vars *vars, int i);
void			calculate_sprite(t_vars *vars);
void			ft_calculate(t_vars *vars);
int				render_next_frame(t_vars *vars);
int				destroy_win(t_vars *vars);
void			load_texture(t_vars *vars, t_pars *pars);
void			initialize_variable(t_vars *vars, t_pars *pars);
void			ft_map(t_vars *vars, t_pars *pars);
void			create_bmp(t_vars *vars);
void			create_img(t_vars *vars);
#endif
