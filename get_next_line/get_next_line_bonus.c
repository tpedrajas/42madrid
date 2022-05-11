/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:50:14 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/11 22:57:43 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	clear_line_data(t_fd_list **lst, t_fd_list *current)
{
	t_line_list	*last;
	size_t		last_index;
	size_t		root_index;

	last = current->line;
	while (last->next)
		last = last->next;
	last_index = 1;
	while (last_index <= BUFFER_SIZE && last->data[last_index - 1] != '\n')
		last_index++;
	root_index = 0;
	while (last_index < BUFFER_SIZE && last->data[last_index])
		current->line->data[root_index++] = last->data[last_index++];
		current->line->data[root_index] = '\0';
	current->line->index = root_index;
	while ((*lst)->fd != current->fd && (*lst)->next)
		lst = &(*lst)->next;
	if (!root_index)
		ft_lstclear(lst, &current->line, root_index);
	else
		ft_lstclear(lst, &current->line->next, root_index);
}

static char	*get_line_data(t_line_list *lst, size_t line_size)
{
	t_line_list	*current;
	size_t		index;
	char		*result;

	result = NULL;
	if (!lst->error && line_size)
	{
		result = (char *)malloc(sizeof(char) * (line_size + 1));
		if (result)
		{
			current = lst;
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
		result = (t_line_list *)malloc(sizeof(t_line_list) * 1);
		if (result)
		{
			result->next = NULL;
			result->index = 0;
			ft_lstadd_data(result, fd);
			lst->next = result;
		}
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
			result = data[index++] == '\n';
		}
		*line_size += check_len;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static t_fd_list	*lst;
	t_fd_list			*current;
	t_line_list			*line;
	size_t				result_len;
	char				*result;

	result = NULL;
	current = ft_lstget(&lst, fd);
	if (current)
	{
		line = current->line;
		result_len = 0;
		while (line && !line->error && !exists_endl(line, &result_len))
			line = add_line_data(line, fd);
		current->line->error = (!line || line->error);
		result = get_line_data(current->line, result_len);
		clear_line_data(&lst, current);
	}
	return (result);
}
