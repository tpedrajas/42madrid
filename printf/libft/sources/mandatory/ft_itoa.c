/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tompedra <tompedra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:22:14 by tompedra          #+#    #+#             */
/*   Updated: 2022/05/13 21:43:28 by tompedra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_rec(char *str, unsigned int n, int index)
{
	if (n < 10)
		str[index] = n + '0';
	else
	{
		ft_itoa_rec(str, n / 10, index - 1);
		str[index] = (n % 10) + '0';
	}
}

char	*ft_itoa(int n)
{
	unsigned int	uintn;
	int				sign;
	size_t			result_len;
	char			*result;

	sign = ft_nbrsign(n);
	uintn = sign * n;
	result_len = ft_nbrlen_base(uintn, 10) + (sign < 0);
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result)
	{
		if (sign < 0)
			result[0] = '-';
		result[result_len] = 0;
		ft_itoa_rec(result, uintn, result_len - 1);
	}
	return (result);
}
