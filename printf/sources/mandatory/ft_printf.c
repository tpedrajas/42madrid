/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:30:32 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/21 00:50:03 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_process_input(const char *format)
{
	char	*mark;
	int		result;
	

	result = 0;
	
	while (format)
	{
		mark = ft_strchr(format, '%');
		if (mark)
		{
			result += (mark - format);
			format = mark + 1;
		}
		
		/*if (*format == '%')
		{
			param_len = ft_process_param_type(*format, params);
			if (param_len != -1)
				result += param_len;
		}*/
		
	}
	return (result);
}

int	ft_printf(char const *format, ...)
{
	va_list	params;
	int		result;

	result = 0;
	va_start(params, format);
	result = ft_process_input(format);
	va_end(params);
	return (result);
}
