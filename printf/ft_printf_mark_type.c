/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mark_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:53:07 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/24 16:56:27 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_process_str_type(const char *param)
{
	char	*param_str;
	int		result_len;
	char	*result;

	result = NULL;
	if (!param)
		param_str = "(null)";
	else
		param_str = param;
	result_len = ft_strlen(param_str) + 1;
	result = (char *)malloc(sizeof(char) * result_len);
	ft_strlcpy(result, param_str, result_len);
	return (result);
}

static char	*ft_process_nbr_type(long param)
{
	char	*result;

	result = ft_ltoa(param);
	return (result);
}

static char	*ft_process_hex_type(size_t param, const char format)
{
	int	result;

	result = ft_nbrlen_base_extra(param, 16);
	return (0);
}

char	*ft_process_mark_type(const char format, va_list args)
{
	char	*result;

	result = NULL;
	if (format == 'c')
		result = ft_process_str_type(va_arg(args, char *));
	else if (format == 's')
		result = ft_process_str_type(va_arg(args, char *));
	else if (format == 'p')
		result = ft_process_hex_type(va_arg(args, size_t), format);
	else if (format == 'd' || format == 'i')
		result = ft_get_nbr_datatype(va_arg(args, int));
	else if (format == 'u')
		result = ft_process_nbr_type(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		result = ft_get_hex_datatype(va_arg(args, unsigned int), format);
	else if (format == '%')
		result = ft_process_str_type("%");
	return (result);
}
