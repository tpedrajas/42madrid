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
#include "get_next_line_internal.h"

void	ft_node_clear(t_line_list *lst)
{
	t_data_node	*current;
	t_data_node	*delete_node;

	if (!lst->node->index)
	{
		delete_node = lst->node;
		lst->node = NULL;
	}
	else
	{
		delete_node = lst->node->next;
		lst->node->next = NULL;
	}
	while (delete_node)
	{
		current = delete_node->next;
		free(delete_node);
		delete_node = current;
	}
}

size_t	ft_node_cpydata(t_data_node *node, char *dest)
{
	int		end_cpy;
	size_t	result;

	result = 0;
	end_cpy = 0;
	while (!end_cpy && result < BUFFER_SIZE && node->data[result])
	{
		dest[result] = node->data[result];
		end_cpy = node->data[result++] == '\n';
	}
	return (result);
}

int	ft_node_incdata(t_data_node *node, int fd)
{
	char	*data;
	size_t	index;
	ssize_t	read_result;
	int		result;

	data = node->data;
	index = BUFFER_SIZE;
	while (index > node->index)
		data[--index] = '\0';
	read_result = read(fd, &data[index], BUFFER_SIZE - index);
	result = 0;
	result |= ls_eof * !read_result;
	result |= ls_error * (read_result < 0);
	node->index += read_result;
	return (result);
}

t_data_node	*ft_node_new(t_line_list *lst, int fd)
{
	t_data_node	*result;

	result = (t_data_node *)malloc(sizeof(t_data_node) * 1);
	if (result)
	{
		result->next = NULL;
		result->index = 0;
		lst->status = ft_node_incdata(result, fd);
	}
	else
		lst->status |= ls_error;
	return (result);
}
