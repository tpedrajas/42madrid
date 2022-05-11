/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:19:42 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/06 01:19:42 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_line_list **lst)
{
	t_line_list	*current;
	t_line_list	*previous;

	current = *lst;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	*lst = NULL;
}

size_t	ft_lstcpy_data(t_line_list *lst, char *dest)
{
	size_t	result;
	int		end_cpy;

	result = 0;
	end_cpy = 0;
	while (!end_cpy && result < BUFFER_SIZE && lst->data[result])
	{
		dest[result] = lst->data[result];
		end_cpy = (lst->data[result++] == '\n');
	}
	return (result);
}

void	ft_lstadd_data(t_line_list *lst, int fd)
{
	char	*data;
	ssize_t	read_result;
	size_t	index;

	data = lst->data;
	index = BUFFER_SIZE;
	while (index > lst->index)
		data[--index] = '\0';
	read_result = read(fd, &data[index], BUFFER_SIZE - index);
	lst->eof = !read_result;
	lst->error = read_result < 0;
	if (!lst->error)
		lst->index += (BUFFER_SIZE - index);
}

t_line_list	*ft_lstnew(int fd)
{
	t_line_list	*result;

	result = NULL;
	if (!read(fd, NULL, 0))
	{
		result = (t_line_list *)malloc(sizeof(t_line_list) * 1);
		if (result)
		{
			result->next = NULL;
			result->index = 0;
			ft_lstadd_data(result, fd);
		}
	}
	return (result);
}
