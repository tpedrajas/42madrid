/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:50:14 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/23 05:57:55 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "get_next_line_internal_bonus.h"

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
		result = (t_data_node *)malloc(sizeof(t_data_node) * 1);
		if (result)
		{
			result->next = NULL;
			result->index = 0;
			lst->status = ft_node_incdata(result, fd);
			node->next = result;
		}
		else
			lst->status |= ls_error;
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
	static t_line_list	list[FOPEN_MAX];
	t_data_node			*current;
	char				*result;

	result = NULL;
	if (!read(fd, NULL, 0) && !(list[fd].status & ls_eof))
	{
		list[fd].status = ls_eof & list[fd].status;
		list[fd].size = 0;
		if (!list[fd].node)
			list[fd].node = ft_node_new(&list[fd], fd);
		current = list[fd].node;
		if (current)
		{
			while (!list[fd].status && !check_line_endl(&list[fd], current))
				current = inc_line_data(&list[fd], current, fd);
			result = get_line_data(&list[fd]);
			clear_line_data(&list[fd]);
		}
	}
	return (result);
}
