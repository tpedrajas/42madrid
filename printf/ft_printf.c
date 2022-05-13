/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:30:32 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/13 22:40:58 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_process_param_type(const char format, va_list args)
{
	int	result;

	result = 0;
	if (format == 'c')
		result = ft_combine_str_param(&va_arg(args, char), format);
	else if (format == 's')
		result = ft_combine_str_param(va_arg(args, char *), format);
	else if (format == 'p')
		result = ft_combine_hex_param(va_arg(args, size_t), format);
	else if (format == 'd' || format == 'i')
		result = ft_combine_llong_param(va_arg(args, int));
	else if (format == 'u')
		result = ft_combine_llong_param(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		result = ft_combine_hex_param(va_arg(args, unsigned int), format);
	else if (format == '%')
		result = ft_combine_str_param(&format, 'c');
	else
		result = -1;
	return (result);
}

int	ft_printf(char const *format, ...)
{
	va_list	params;
	int		result;

	result = 0;
	va_start(params, format);


	while (*format)
	{
		if (*format == '%')
		{
			param_len = ft_process_param_type(*format, params);
			if (param_len != -1)
				result += param_len;
		}
		
	}
	va_end(params);
	return (result);
}

int	main(void)
{
	printf("%03d", 10);
}
