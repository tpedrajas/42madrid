/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:30:36 by tompedra          #+#    #+#             */
<<<<<<< HEAD:printf/libftprintf.h
/*   Updated: 2022/05/21 23:27:12 by tompedra         ###   ########.fr       */
=======
/*   Updated: 2022/05/19 22:39:47 by tompedra         ###   ########.fr       */
>>>>>>> b8e5cdc60d0aa779e2023b6d56733125768d2d50:printf/ft_printf.h
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

<<<<<<< HEAD:printf/libftprintf.h
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
char	*ft_process_mark_type(const char format, va_list args);
=======
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
>>>>>>> b8e5cdc60d0aa779e2023b6d56733125768d2d50:printf/ft_printf.h

#endif
