/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:53:22 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/27 12:53:29 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*inter;

	while (*lst && del)
	{
		inter = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = inter;
	}
	*lst = NULL;
}
