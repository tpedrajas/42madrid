/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mark.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:08:05 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/21 23:24:16 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_process_mark_flags(const char *format, t_mark *mark)
{
	int exists_flag;
	int	result;

	result = 0;
	exists_flag = 1;
	while (exists_flag)
	{
		if (*format == '-')
			mark->justify = 'l';
		else if (*format == '0' || *format == ' ')
		{
			mark->fill = 1;
			mark->fill_char = *format;
		}
		//else if (*format == '#')

		else if (*format == '+')
			mark->sign = 1;
		else
		{
			exists_flag = 0;
			result--;
		}
		result++;
	}
	return (result - 1);
}

static int	ft_process_mark_width(const char *format)
{
	return (0);
}

static int	ft_process_mark_precision(const char *format)
{
	return (0);
}

int	ft_process_mark(const char *format, va_list args)
{
	t_mark	mark;
	int		result;

	result = 0;
	mark.data = NULL;

	ft_process_mark_type(*format, &mark, args);
	if (result)
	{
		//ft_process_mark_flags(format, result);
		if (ft_process_mark_type(*format, result, args) == -1)
		{
			free(result);
			result = NULL;
		}
	}
	return (result);
}