/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:30:32 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/25 23:38:54 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_process_param(char const format, va_list args)
{
	int	result;

	result = 0;
	if (format == 'c')

	if (format == 's')

	if (format == 'p')

	if (format == 'd')

	if (format == 'i')

	if (format == 'u')

	if (format == 'x')

	if (format == 'X')

	if (format == '%')
		
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
			result += ft_process_param(format, params);
		}
		
	}
	va_end(params);
	return (result);
}