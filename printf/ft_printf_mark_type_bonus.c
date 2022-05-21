/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mark_type_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:16:26 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/21 23:16:46 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

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
