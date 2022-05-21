/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:12:15 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/02 00:28:42 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	clear_line_data(t_line_list **lst)
{
	t_line_list	*last;
	size_t		last_index;
	size_t		root_index;

	last = *lst;
	while (last->next)
		last = last->next;
	last_index = 1;
	while (last_index <= BUFFER_SIZE && last->data[last_index - 1] != '\n')
		last_index++;
	root_index = 0;
	while (last_index < BUFFER_SIZE && last->data[last_index])
		(*lst)->data[root_index++] = last->data[last_index++];
	(*lst)->data[root_index] = '\0';
	(*lst)->index = root_index;
	if (!root_index)
		ft_lstclear(lst);
	else
		ft_lstclear(&(*lst)->next);
}

static char	*get_line_data(t_line_list **lst, size_t line_size)
{
	t_line_list	*current;
	size_t		index;
	char		*result;

	result = NULL;
	if (!(*lst)->error && line_size)
	{
		result = (char *)malloc(sizeof(char) * (line_size + 1));
		if (result)
		{
			current = *lst;
			index = 0;
			while (current && index < line_size)
			{
				index += ft_lstcpy_data(current, &result[index]);
				current = current->next;
			}
			result[line_size] = '\0';
		}
	}
	return (result);
}

static t_line_list	*add_line_data(t_line_list *lst, int fd)
{
	t_line_list	*result;

	result = lst;
	if (lst->index < BUFFER_SIZE)
		ft_lstadd_data(result, fd);
	else
	{
		result = ft_lstnew(fd);
		if (result)
			lst->next = result;
	}
	return (result);
}

static int	exists_endl(t_line_list *lst, size_t *line_size)
{
	char	*data;
	size_t	index;
	size_t	check_len;
	int		result;

	result = lst->eof;
	if (!result)
	{
		data = lst->data;
		index = *line_size % BUFFER_SIZE;
		check_len = 0;
		while (!result && index < BUFFER_SIZE && data[index])
		{
			check_len++;
			result = (data[index++] == '\n');
		}
		*line_size += check_len;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static t_line_list	*list;
	t_line_list			*current;
	size_t				result_len;
	char				*result;

	result = NULL;
	if (!list)
		list = ft_lstnew(fd);
	if (list)
	{
		current = list;
		result_len = 0;
		while (current && !current->error && !exists_endl(current, &result_len))
			current = add_line_data(current, fd);
		list->error = (!current || current->error);
		result = get_line_data(&list, result_len);
		clear_line_data(&list);
	}
	return (result);
}
