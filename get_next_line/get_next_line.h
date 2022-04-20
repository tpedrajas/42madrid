/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:12:47 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/19 23:36:13 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_line_list
{
	char				data[BUFFER_SIZE + 1];
	struct s_line_list	*next;
	size_t				index;
	int					eof;
	int					error;
}	t_line_list;

void		ft_lstclear(t_line_list **lst);
size_t		ft_lstcpy_data(t_line_list *lst, char *dest);
void		ft_lstadd_data(t_line_list *lst, int fd);
t_line_list	*ft_lstnew(int fd);
char		*get_next_line(int fd);

#endif
