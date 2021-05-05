/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:07:05 by slarrana          #+#    #+#             */
/*   Updated: 2020/02/23 16:19:56 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strfree(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

static int	putline(char **res, char **line)
{
	int		a;
	char	*tmp;

	a = 0;
	while (res[0][a] != '\n' && res[0][a] != '\0')
		a++;
	*line = ft_substr(res[0], 0, a);
	tmp = ft_strdup(&res[0][a + 1]);
	free(res[0]);
	res[0] = tmp;
	return (1);
}

static int	value(char **res, char **line, int rd)
{
	if (rd < 0)
		return (-1);
	else if (rd == 0 && res[0] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if (ft_strchr(res[0], '\n'))
		return (putline(res, line));
	else
	{
		*line = ft_strdup(res[0]);
		ft_strfree(&res[0]);
		return (0);
	}
}

int			get_next_line(int fd, char **line)
{
	int			rd;
	char		buffer[BUFFER_SIZE + 1];
	static char	*res[1];
	char		*tmp;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		if (res[0] == NULL)
			res[0] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(res[0], buffer);
			free(res[0]);
			res[0] = tmp;
		}
		if (ft_strchr(res[0], '\n'))
			break ;
	}
	return (value(res, line, rd));
}
