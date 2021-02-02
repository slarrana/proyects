/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 18:13:50 by slarrana          #+#    #+#             */
/*   Updated: 2021/01/02 18:16:12 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_pars
{
	int				i;
	int				x;
	int				y;
	char			*north_path;
	char			*north_south;
	char			*north_east;
	char			*north_weast;
	char			*path_sprite;
	int				floor[3];
	unsigned int	floor_rgb;
	int				sky[3];
	unsigned int	sky_rgb;
	int				width;
	int				height;
	char			**map;
	int				pos_x;
	int				pos_y;
	int				dir_x;
	int				dir_y;
	int				flag;
	int				n;
	int				map_start;
	int				j;
	char			*str;
	int				fd;
	double			plane_x;
	double			plane_y;
	int				save;
}					t_pars;

void				advance_space(char *str, t_pars *pars);
char				*get_path(char *str);
void				free_memory(t_pars *pars);
int					ft_error_variables(t_pars *pars, char *str);
int					check_variables(t_pars *pars);
void				save_map(char *str, t_pars *pars, int i);
void				free_map(t_pars *pars);
void				ft_start_pos(t_pars *pars, int i, int j);
void				ubication(t_pars *pars);
void				map_error(t_pars *pars, char *str);
void				check_map(t_pars *pars, int i, int j, int p);
void				invalid_character(char *str, t_pars *pars);
int					check_cub(char *str);
void				initializate(t_pars *pars);
void				repe(t_pars *pars);
void				ft_control_map(t_pars *pars, int i, int j);
void				check_space(t_pars *pars);
int					check_first_line(t_pars *pars, int i, int f);
int					check_last_line(t_pars *pars, int i, int f);
int					check_first_column(t_pars *pars, int i, int f);
int					check_last_column(t_pars *pars, int i, int f);
void				check_perimet(t_pars *pars);
unsigned int		ft_rgb(int red, int green, int blue);
void				check_north_path(t_pars *pars);
void				check_north_east(t_pars *pars);
void				check_north_south(t_pars *pars);
void				check_north_weast(t_pars *pars);
void				check_path_sprite(t_pars *pars);
void				ft_resolution(t_pars *pars, char *str);
void				ft_path_no(t_pars *pars, char *str);
void				ft_path_so(t_pars *pars, char *str);
void				ft_path_we(t_pars *pars, char *str);
void				ft_path_ea(t_pars *pars, char *str);
void				ft_path_sprite(t_pars *pars, char *str);
void				ft_floor0(t_pars *pars, char *str);
void				ft_floor1(t_pars *pars, char *str);
void				ft_floor2(t_pars *pars, char *str);
void				ft_floor(t_pars *pars, char *str);
void				ft_sky0(t_pars *pars, char *str);
void				ft_sky1(t_pars *pars, char *str);
void				ft_sky2(t_pars *pars, char *str);
void				ft_sky(t_pars *pars, char *str);
int					ft_start_map(t_pars *pars, char *str);
void				ft_error_line(t_pars *pars, char *str, int fd);
int					check_ifs(t_pars *pars, char *str, int fd);
void				ft_readfd(t_pars *pars, char *str, int fd);
void				check_args(int argc, char **argv, t_pars *pars);
void				ft_width_height(t_pars *pars);
void				ft_maping(t_pars *pars, char *str);
void				ft_parse(t_pars *pars, int argc, char **argv);

#endif
