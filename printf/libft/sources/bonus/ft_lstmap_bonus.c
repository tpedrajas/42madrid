/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:37:37 by tompedra          #+#    #+#             */
/*   Updated: 2022/03/28 18:37:37 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew_safe(void *content, void (*del)(void *))
{
	t_list	*result;

	result = ft_lstnew(content);
	if (!result && del)
		del(content);
	return (result);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*result;

	result = NULL;
	if (f && lst)
	{
		result = ft_lstnew_safe(f(lst->content), del);
		lst = lst->next;
		while (lst)
		{
			new = ft_lstnew_safe(f(lst->content), del);
			if (new)
			{
				ft_lstadd_back(&result, new);
				lst = lst->next;
			}
			else
			{
				ft_lstclear(&result, del);
				result = NULL;
				lst = NULL;
			}
		}
	}
	return (result);
}
