/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_internal.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:58:33 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/23 01:43:11 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_INTERNAL_H
# define GET_NEXT_LINE_INTERNAL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

enum e_line_status
{
	ls_eof = 1,
	ls_error = 2
};

typedef struct s_data_node
{
	char				data[BUFFER_SIZE];
	struct s_data_node	*next;
	size_t				index;
}	t_data_node;

typedef struct s_line_list
{
	t_data_node	*node;
	int			status;
	size_t		size;
}	t_line_list;

void		ft_node_clear(t_line_list *lst);
size_t		ft_node_cpydata(t_data_node *node, char *dest);
int			ft_node_incdata(t_data_node *node, int fd);
t_data_node	*ft_node_new(t_line_list *lst, int fd);

#endif
