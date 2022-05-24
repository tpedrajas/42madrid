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

static void	clear_line_data(t_line_list *lst)
{
	t_data_node	*last;
	size_t		last_index;
	size_t		root_index;

	if (lst->node)
	{
		last = lst->node;
		while (last->next)
			last = last->next;
		last_index = 1;
		while (last_index <= BUFFER_SIZE && last->data[last_index - 1] != '\n')
			last_index++;
		root_index = 0;
		while (last_index < BUFFER_SIZE && last->data[last_index])
			lst->node->data[root_index++] = last->data[last_index++];
		lst->node->data[root_index] = '\0';
		lst->node->index = root_index;
		ft_node_clear(lst);
	}
}

static char	*get_line_data(t_line_list *lst)
{
	t_data_node	*current;
	size_t		index;
	char		*result;

	result = NULL;
	if (!(lst->status & ls_error) && lst->size)
	{
		result = (char *)malloc(sizeof(char) * (lst->size + 1));
		if (result)
		{
			index = 0;
			current = lst->node;
			while (current && index < lst->size)
			{
				index += ft_node_cpydata(current, &result[index]);
				current = current->next;
			}
			result[lst->size] = '\0';
		}
	}
	return (result);
}

static t_data_node	*inc_line_data(t_line_list *lst, t_data_node *node, int fd)
{
	t_data_node	*result;

	if (node->index < BUFFER_SIZE)
	{
		lst->status = ft_node_incdata(node, fd);
		result = node;
	}
	else
	{
		result = ft_node_new(lst, fd);
		node->next = result;
	}
	if (lst->status & ls_error)
		result = NULL;
	return (result);
}

static int	check_line_endl(t_line_list *lst, t_data_node *node)
{
	size_t	index;
	size_t	check_len;
	int		result;

	result = 0;
	index = lst->size % BUFFER_SIZE;
	check_len = 0;
	while (!result && index < BUFFER_SIZE && node->data[index])
	{
		check_len++;
		result = node->data[index++] == '\n';
	}
	lst->size += check_len;
	return (result);
}

char	*get_next_line(int fd)
{
	static t_line_list	list;
	t_data_node			*current;
	char				*result;

	result = NULL;
	if (!read(fd, NULL, 0) && !(list.status & ls_eof))
	{
		list.status = ls_eof & list.status;
		list.size = 0;
		if (!list.node)
			list.node = ft_node_new(&list, fd);
		current = list.node;
		if (current)
		{
			while (!list.status && !check_line_endl(&list, current))
				current = inc_line_data(&list, current, fd);
			result = get_line_data(&list);
			clear_line_data(&list);
		}
	}
	return (result);
}
