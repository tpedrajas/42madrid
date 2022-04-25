/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:53:36 by tompedra          #+#    #+#             */
/*   Updated: 2022/04/09 21:17:53 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_max_long(void)
{
	return (~0UL >> 1);
}

static int	ft_check_limits(size_t n, int sign)
{
	int	result;

	result = (n * sign);
	if (n > ft_max_long() && sign == 1)
		result = -1;
	if (n > ft_max_long() + 1 && sign == -1)
		result = 0;
	return (result);
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		nbr_len;
	size_t	result;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
		sign = 44 - *(str++);
	result = 0;
	nbr_len = 0;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*(str++) - '0');
		nbr_len++;
	}
	if (nbr_len > 19)
		result = ft_max_long() + 2;
	return (ft_check_limits(result, sign));
}
