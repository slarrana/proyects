/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:54:15 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/29 16:52:08 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*inter;

	if (new)
	{
		inter = *lst;
		if (!*lst)
		{
			*lst = new;
			new->next = NULL;
		}
		else
		{
			inter = ft_lstlast(*lst);
			inter->next = new;
		}
	}
}
