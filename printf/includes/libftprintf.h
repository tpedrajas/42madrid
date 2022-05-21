/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:30:36 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/21 00:15:47 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

enum e_printflags
{
	justify = 1,
	fill = 2,
	precision = 4,
	alternative = 8,
	sign = 16
};

typedef struct s_mark
{
	char			*data;
	struct s_mark	*next;
	char			justify;
	int				fill;
	char			fill_char;
	int				precision;
	int				sign;
}	t_mark;

int		ft_printf(char const *format, ...);
t_mark	*ft_process_mark(const char *format, va_list args);
char	*ft_get_str_datatype(const char *param, const char format);
char	*ft_get_nbr_datatype(size_t param);
char	*ft_get_hex_datatype(size_t param, const char format);

#endif
