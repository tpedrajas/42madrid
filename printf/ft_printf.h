/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:30:36 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/19 22:39:47 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

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
