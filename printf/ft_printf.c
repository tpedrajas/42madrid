/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 20:30:32 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/24 16:56:11 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_process_input(const char *format, va_list params)
{
	char	*mark;
	int		result;

	result = 0;
	if (format)
	{
		while (*format)
		{
			mark = ft_strchr(format, '%');
			if (!mark)
				mark = (char *)(format + ft_strlen(format));
			write(STDOUT_FILENO, format, mark - format);
			result += (mark - format);
			format = mark + (*mark != '\0');
			if (*format)
				result += ft_process_mark_type(*format, params);
		}
	}
	return (result);
}

int	ft_printf(char const *format, ...)
{
	va_list	params;
	int		result;

	result = 0;
	va_start(params, format);
	result = ft_process_input(format, params);
	va_end(params);
	return (result);
}
