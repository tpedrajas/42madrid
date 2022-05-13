/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_param_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:53:07 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/13 22:16:08 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_combine_str_param(const char *param, const char format)
{
	char	*str_result;
	int		result;

	str_result = param;
	result = -1;
	if (format == 'c')
		result = 1;
	if (format == 's')
	{
		if (!param)
			str_result = "(null)";
		result = strlen(str_param);
	}
	write(1, str_param, result);
	return (result);
}

int	ft_combine_ullong_param(size_t param, const char format)
{
	int	result;

	result = ft_ullonglen_base_extra(param, 10);
	return (0);
}

int	ft_combine_hex_param(size_t param, char format)
{
	int	result;

	result = ft_ullonglen_base_extra(param, 16);
	return (0);
}
