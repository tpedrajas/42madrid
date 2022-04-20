/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:54:19 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/19 23:23:28 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lstclear(t_fd_list **lst, t_line_list **line, size_t data_index)
{
	t_fd_list	*delete;
	t_line_list	*current;
	t_line_list	*previous;

	current = *line;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	*line = NULL;
	if (!data_index)
	{
		delete = *lst;
		*lst = delete->next;
		free(delete);
	}
}

size_t	ft_lstcpy_data(t_line_list *lst, char *dest)
{
	size_t	result;
	int		end_cpy;

	result = 0;
	end_cpy = 0;
	while (!end_cpy && lst->data[result])
	{
		dest[result] = lst->data[result];
		end_cpy = lst->data[result++] == '\n';
	}
	return (result);
}

void	ft_lstadd_data(t_line_list *lst, int fd)
{
	char	*data;
	ssize_t	read_result;
	size_t	index;

	data = lst->data;
	index = BUFFER_SIZE + 1;
	while (index > lst->index)
		data[--index] = '\0';
	read_result = read(fd, &data[index], BUFFER_SIZE - index);
	lst->eof = !read_result;
	lst->error = read_result < 0;
	if (!lst->error)
		lst->index += (BUFFER_SIZE - index);
}

t_fd_list	*ft_lstnew(int fd)
{
	t_line_list	*line;
	t_fd_list	*result;

	result = (t_fd_list *)malloc(sizeof(t_fd_list) * 1);
	if (result)
	{
		result->next = NULL;
		result->fd = fd;
		line = (t_line_list *)malloc(sizeof(t_line_list) * 1);
		if (line)
		{
			line->next = NULL;
			line->index = 0;
			ft_lstadd_data(line, fd);
			result->line = line;
		}
		else
		{
			free(result);
			result = NULL;
		}
	}
	return (result);
}

t_fd_list	*ft_lstget(t_fd_list **lst, int fd)
{
	t_fd_list	*result;

	result = NULL;
	if (!read(fd, NULL, 0))
	{
		if (!(*lst))
		{
			printf("Creamos el nodo estatico\n");
			*lst = ft_lstnew(fd);
			result = *lst;
		}
		else
		{
			result = *lst;
			while (result->fd != fd && result->next)
				result = result->next;
			if (result->fd != fd)
			{
				result->next = ft_lstnew(fd);
				result = result->next;
			}
		}
	}
	return (result);
}
