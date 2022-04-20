/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 21:50:45 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/19 23:22:13 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

typedef struct s_fd_list
{
	t_line_list			*line;
	struct s_fd_list	*next;
	int					fd;
}	t_fd_list;

void		ft_lstclear(t_fd_list **lst, t_line_list **line, size_t data_index);
size_t		ft_lstcpy_data(t_line_list *lst, char *dest);
void		ft_lstadd_data(t_line_list *lst, int fd);
t_fd_list	*ft_lstnew(int fd);
t_fd_list	*ft_lstget(t_fd_list **lst, int fd);
char		*get_next_line(int fd);

#endif
