/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:23:17 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/27 13:42:26 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	a;
	void	*ret;

	if (!(ret = malloc((count * size))))
		return (0);
	a = 0;
	while (a < (count * size))
	{
		((char *)ret)[a] = 0;
		a++;
	}
	return (ret);
}
