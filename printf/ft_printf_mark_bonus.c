/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mark_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:15:46 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/21 23:16:06 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

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

static void	ft_process_mark_type(const char format, t_mark *mark, va_list args)
{
	if (format == 'c')
		mark->data = ft_get_str_datatype(va_arg(args, char *), format);
	else if (format == 's')
		mark->data = ft_get_str_datatype(va_arg(args, char *), format);
	else if (format == 'p')
		mark->data = ft_get_hex_datatype(va_arg(args, size_t), format);
	else if (format == 'd' || format == 'i')
		mark->data = ft_get_nbr_datatype(va_arg(args, int));
	else if (format == 'u')
		mark->data = ft_get_nbr_datatype(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		mark->data = ft_get_hex_datatype(va_arg(args, unsigned int), format);
	else if (format == '%')
		mark->data = ft_get_str_datatype(&format, 'c');
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