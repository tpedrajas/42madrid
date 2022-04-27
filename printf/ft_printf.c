/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:30:32 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/27 21:40:42 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_process_param(char const format, va_list args)
{
	int	result;

	result = 0;
	/*if (format == 'c')
		result = ft_print_char_param(va_arg(args, char))
	else if (format == 's')
		result = ft_print_str_param(va_arg(args, char *));
	else if (format == 'p')
		result = ft_print_ptr_param(va_arg(args, size_t))
	else if (format == 'd' || format == 'i')
		result = ft_print_int_param(va_arg(args, int));
	else if (format == 'u')
		result = ft_print_uint_param(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		result = ft_print_hex_param(va_arg(args, unsigned int), format);
	else if (format == '%')
		result = ft_print_char_param(format);
	else
		result = -1;*/
	return (result);
}

int	ft_printf(char const *format, ...)
{
	va_list	params;
	char	**split_params;
	int		result;

	result = 0;
	va_start(params, format);
	while (*format)
	{
		param_len = ft_strchr(format, '%') - format;
		result = 
	}

	while (*format)
	{
		if (*format == '%')
		{
			param_len = ft_process_param(*format, params);
			if (param_len != -1)
				result += param_len;
		}
		
	}
	va_end(params);
	return (result);
}

int	main(void)
{
	printf("% hola %");
}
