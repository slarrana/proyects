/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:17:37 by slarrana          #+#    #+#             */
/*   Updated: 2021/02/01 15:56:48 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void		write_data_header(t_vars *vars, int size, int fd)
{
	unsigned char	header[54];

	ft_memset(header, 0, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(vars->x);
	header[19] = (unsigned char)(vars->x >> 8);
	header[20] = (unsigned char)(vars->x >> 16);
	header[21] = (unsigned char)(vars->x >> 24);
	header[22] = (unsigned char)(vars->y);
	header[23] = (unsigned char)(vars->y >> 8);
	header[24] = (unsigned char)(vars->y >> 16);
	header[25] = (unsigned char)(vars->y >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
}

static void		write_screenshot(int fd, t_vars *vars, int width, int height)
{
	int				x;
	unsigned int	color;

	height--;
	while (height >= 0)
	{
		x = 0;
		while (x < width)
		{
			color = *(unsigned int *)(vars->imagen.addr + (height *
			vars->imagen.line_length + (x * (vars->imagen.bits / 8))));
			write(fd, &color, 4);
			x++;
		}
		height--;
	}
}

void			create_bmp(t_vars *vars)
{
	int	fd;
	int	size;

	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	size = 54 + (vars->x * vars->y) * 4;
	write_data_header(vars, size, fd);
	write_screenshot(fd, vars, vars->x, vars->y);
	close(fd);
	mlx_destroy_image(vars->mlx, vars->imagen.img);
	exit(0);
}
