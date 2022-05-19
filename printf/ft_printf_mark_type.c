/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mark_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:53:07 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/19 22:39:55 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_str_datatype(const char *param, const char format)
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
		result = strlen(str_result);
	}
	write(1, str_result, result);
	return (result);
}

char	*ft_get_nbr_datatype(size_t param)
{
	int	result;

	result = ft_nbrlen_base_extra(param, 10);
	return (0);
}

char	*ft_get_hex_datatype(size_t param, const char format)
{
	int	result;

	result = ft_nbrlen_base_extra(param, 16);
	return (0);
}
