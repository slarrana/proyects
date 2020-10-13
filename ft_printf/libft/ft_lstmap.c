/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slarrana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:54:50 by slarrana          #+#    #+#             */
/*   Updated: 2020/01/29 17:05:12 by slarrana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if (!(new = ft_lstnew(f(lst->content))))
		return (NULL);
	result = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(result->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		result = result->next;
	}
	result->next = NULL;
	return (new);
}
