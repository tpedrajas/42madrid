/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:30:36 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/27 20:46:04 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_print_char_param(char param);
int	ft_print_str_param(char *param);
int	ft_print_ptr_param(size_t param);
int	ft_print_int_param(int param);
int	ft_print_uint_param(unsigned int param);
int	ft_print_hex_param(unsigned int param);

int	ft_printf(char const *format, ...);

#endif
